

// Load Wi-Fi library
#include <led_animations.h>
#include <WiFi.h>


#include <HTTPClient.h>
#include <WiFiClient.h>

QueueHandle_t queue;
int queueSize = 10;
animations::led_animations anime;
// Replace with your network credentials
const char *ssid = "PoliteaNET";//"VIVOFIBRA-D8FB";
const char *password = "PoliteaN";//"72234ED8FB";
String character_name = "ANIMUS_LED";
const char *serverName = "http://192.168.1.104/device_register";
String IP_Address;
void RegisterInServer();
void Task1code(void *param);
// Set web server port number to 80
WiFiServer server(80);

// Decode HTTP GET value
String redString = "0";
String greenString = "0";
String blueString = "0";
String carregarString = "0";
String medioString = "0";
String doenteString = "0";

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int pos6 = 0;
int pos7 = 0;
int pos8 = 0;

// Variable to store the HTTP req  uest
String header;

// Red, green, and blue pins for PWM control
const int redPin = 13;   // 13 corresponds to GPIO13
const int greenPin = 12; // 12 corresponds to GPIO12
const int bluePin = 14;  // 14 corresponds to GPIO14

// Setting PWM frequency, channels and bit resolution
const int freq = 5000;
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;
// Bit resolution 2^8 = 256
const int resolution = 8;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

TaskHandle_t Task1;

void setup()
{
  queue = xQueueCreate(queueSize, sizeof(int));

  Serial.begin(115200);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);  
  WiFi.disconnect();
  Serial.println("wait for networks");
  delay(1000);
  int n = WiFi.scanNetworks();

  Serial.println(n);
  for(int i =0; i<n;i++)
  {
    Serial.println(WiFi.SSID(i));
    if(!strcmp(ssid,WiFi.SSID(i).c_str()))
    {
      Serial.println("wifi found!!!");
    }
    delay(200);
  }


  WiFi.begin(ssid, password);
  wl_status_t state = WiFi.status();
  while (state != WL_CONNECTED)
  {
    char prnt[30];
    state = WiFi.status();
    
    sprintf(prnt,"Current State: %d", (int)state);
    Serial.println(prnt);
    delay(1000);
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  IP_Address = WiFi.localIP().toString();
  server.begin();
  RegisterInServer();
  xTaskCreatePinnedToCore(
      Task1code, /* Function to implement the task */
      "Task1",   /* Name of the task */
      15000,     /* Stack size in words */
      NULL,      /* Task input parameter */
      0,         /* Priority of the task */
      &Task1,    /* Task handle. */
      0);        /* Core where the task should run */
}
void Task1code(void *parameter)
{
  animations::animation_types element = animations::_dead;

  for (;;)
  {
    int tmp;
    Serial.println("before wait");
    BaseType_t ret = xQueueReceive(queue, &tmp, portTICK_PERIOD_MS * 100);
    if (ret != errQUEUE_EMPTY)
    {
      element = (animations::animation_types)tmp;
      Serial.println("animation selected:");
      Serial.println(tmp);
    }
    
    anime.animate(element);
    Serial.println("after animation");
  }
}

void loop()
{
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client)
  { // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client."); // print a message out in the serial port
    String currentLine = "";       // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime)
    { // loop while the client's connected
      currentTime = millis();
      if (client.available())
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then

        header += c;
        if (c == '\n')
        { // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0)
          {
            Serial.write(header.c_str()); // print it out the serial monitor
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">");
            client.println("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/jscolor/2.0.4/jscolor.min.js\"></script>");
            client.println("</head><body><div class=\"container\"><div class=\"row\"><h1>ESP Color Picker</h1></div>");
            client.println("<a class=\"btn btn-primary btn-lg\" href=\"#\" id=\"change_color\" role=\"button\">Change Color</a> ");

            for(int i=0; i<INSTALLED_AMOUNT ; i++)
            {
              client.print("<a class=\"btn btn-primary btn-lg\" href=\"?");
              client.print(anime.animations_names[i]);
              client.print("&\" id=\"");
              client.print(anime.animations_names[i]);
              client.print("\" role=\"button\">");
              client.print(anime.animations_names[i]);
              client.println("</a> ");
            }
            
            client.println("<input class=\"jscolor {onFineChange:'update(this)'}\" id=\"rgb\"></div>");
            client.println("<script>function update(picker) {document.getElementById('rgb').innerHTML = Math.round(picker.rgb[0]) + ', ' +  Math.round(picker.rgb[1]) + ', ' + Math.round(picker.rgb[2]);");
            client.println("document.getElementById(\"change_color\").href=\"??r\" + Math.round(picker.rgb[0]) + \"g\" +  Math.round(picker.rgb[1]) + \"b\" + Math.round(picker.rgb[2]) + \"c0d0m0&\";}</script></body></html>");
            // The HTTP response ends with another blank line
            client.println();
            if(header.indexOf("GET /?")>=0)
            {
              pos1 = header.indexOf("?");
              pos2 = header.indexOf("&");
              String selected_animatino = header.substring(pos1+1,pos2);
              
              
              Serial.println(selected_animatino);
              for(int i=0; i<INSTALLED_AMOUNT;i++)
              if(!selected_animatino.compareTo(anime.animations_names[i]))
              {
                
                int j = anime.available_animations[i];
                xQueueSend(queue, &j, portMAX_DELAY);
                break;
              } 
            }
            // Request sample: /?r201g32b255&
            // Red = 201 | Green = 32 | Blue = 255
            if (header.indexOf("GET /??r") >= 0)
            {              
              pos1 = header.indexOf('r');
              pos2 = header.indexOf('g');
              pos3 = header.indexOf('b');
              pos4 = header.indexOf('c');
              pos5 = header.indexOf('d');
              pos6 = header.indexOf('m');
              pos7 = header.indexOf('&');
              redString = header.substring(pos1 + 1, pos2);
              greenString = header.substring(pos2 + 1, pos3);
              blueString = header.substring(pos3 + 1, pos4);
              carregarString = header.substring(pos4 + 1, pos5);
              doenteString = header.substring(pos5 + 1, pos6);
              medioString = header.substring(pos6 + 1, pos7);

              int i = 0;
              if (carregarString.toInt() == 1)
              {
                i = 1;
              }
              else if (doenteString.toInt() == 1)
              {
                i = 2;
              }
              else if (medioString.toInt() == 1)
              {
                i = 3;
              }
              xQueueSend(queue, &i, portMAX_DELAY);
            }
            // Break out of the while loop

            break;
          }
          else
          { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        }
        else if (c != '\r')
        {                   // if you got anything else but a carriage return character,
          currentLine += c; // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  else
  {
    delay(10);
  }
}



void RegisterInServer()
{
      HTTPClient http;
      WiFiClient client;
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);
      Serial.println(client);
      Serial.println(serverName);
      // If you need Node-RED/server authentication, insert user and password below
      //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
      
      // Specify content-type header
      http.addHeader("Content-Type", "application/json");
      // Data to send with HTTP POST
      //String httpRequestData = "api_key=tPmAT5Ab3j7F9&sensor=BME280&value1=24.25&value2=49.54&value3=1005.14";           

      String register_json = "{\"character\":\"";
      register_json += character_name;
      register_json+="\",\"IP\":\"";
      register_json+=IP_Address;
      register_json+="\",\"PORT\":\"80\",\"type\":\"Injector\",\"endpoints\":[";
      for(int i=0 ; i<INSTALLED_AMOUNT;i++)
      {
        register_json+="\"";
        register_json+=anime.animations_names[i];
        if(i < INSTALLED_AMOUNT-1)
        {
          register_json+="\",";
        }
        else
        {
          register_json+="\"";
        }
      }

      register_json+="],\"animations\":[";
      for(int i=0 ; i<INSTALLED_AMOUNT;i++)
      {
        register_json+="\"";
        register_json+=anime.animations_names[i];
        if(i < INSTALLED_AMOUNT-1)
        {
          register_json+="\",";
        }
        else
        {
          register_json+="\"";
        }
        
      }
      register_json+="]}";
      Serial.println(register_json);
      int httpResponseCode = http.POST(register_json);
 
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
}