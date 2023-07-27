#include "led_animations.h"

using namespace animations;
#define SOMA_ANIMATION_STEP 2
void led_animations::red_alert(){
static int red_alert_step = 0;

    if(red_alert_step<= 50)
    {
        red_alert_step+=1;
        for(int i=0;i<NUM_LEDS_SOMA; i++)
        {
            soma_leds[i].setRGB(5*red_alert_step,0,0);
        }
    }
    else
    {
        red_alert_step=0;
    }
}
void led_animations::yellow_alert(){
static int yellow_alert_step = 0;
    
    switch (yellow_alert_step)
    {
    case 0:
        for(int i =0; i<NUM_LEDS_SOMA; i++)
        {
            soma_leds[i] = CRGB::Black;
        }

    break;
    case 1*SOMA_ANIMATION_STEP:
        soma_leds[7] = CRGB::Yellow;
        soma_leds[8] = CRGB::Yellow;
        break;
    case 2*SOMA_ANIMATION_STEP:
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        break;
    case 3*SOMA_ANIMATION_STEP:
        soma_leds[5] = CRGB::Yellow;
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        soma_leds[10] = CRGB::Yellow;
        break;      
    case 4*SOMA_ANIMATION_STEP:
        soma_leds[4] = CRGB::Yellow;
        soma_leds[5] = CRGB::Yellow;
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        soma_leds[10] = CRGB::Yellow;
        soma_leds[11] = CRGB::Yellow;
        break;      
    case 5*SOMA_ANIMATION_STEP:
        soma_leds[3] = CRGB::Yellow;
        soma_leds[4] = CRGB::Yellow;
        soma_leds[5] = CRGB::Yellow;
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        soma_leds[10] = CRGB::Yellow;
        soma_leds[11] = CRGB::Yellow;
        soma_leds[12] = CRGB::Yellow;
        break;                        
    case 6*SOMA_ANIMATION_STEP:
        soma_leds[2] = CRGB::Yellow;
        soma_leds[3] = CRGB::Yellow;
        soma_leds[4] = CRGB::Yellow;
        soma_leds[5] = CRGB::Yellow;
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        soma_leds[10] = CRGB::Yellow;
        soma_leds[11] = CRGB::Yellow;
        soma_leds[12] = CRGB::Yellow;
        soma_leds[13] = CRGB::Yellow;
        break;
    case 7*SOMA_ANIMATION_STEP:
        soma_leds[1] = CRGB::Yellow;
        soma_leds[2] = CRGB::Yellow;
        soma_leds[3] = CRGB::Yellow;
        soma_leds[4] = CRGB::Yellow;
        soma_leds[5] = CRGB::Yellow;
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        soma_leds[10] = CRGB::Yellow;
        soma_leds[11] = CRGB::Yellow;
        soma_leds[12] = CRGB::Yellow;
        soma_leds[13] = CRGB::Yellow;
        soma_leds[14] = CRGB::Yellow;
        break;        
    case 8*SOMA_ANIMATION_STEP:
        soma_leds[0] = CRGB::Yellow;
        soma_leds[1] = CRGB::Yellow;
        soma_leds[2] = CRGB::Yellow;
        soma_leds[3] = CRGB::Yellow;
        soma_leds[4] = CRGB::Yellow;
        soma_leds[5] = CRGB::Yellow;
        soma_leds[6] = CRGB::Yellow;
        soma_leds[7] = CRGB::Yellow;    
        soma_leds[8] = CRGB::Yellow;
        soma_leds[9] = CRGB::Yellow;
        soma_leds[10] = CRGB::Yellow;
        soma_leds[11] = CRGB::Yellow;
        soma_leds[12] = CRGB::Yellow;
        soma_leds[13] = CRGB::Yellow;
        soma_leds[14] = CRGB::Yellow;
        soma_leds[15] = CRGB::Yellow;
        break;                
    default:
        break;
    }
    yellow_alert_step+=1;
    if(yellow_alert_step>8*SOMA_ANIMATION_STEP)
    {
        yellow_alert_step = 0;
    }

}
void led_animations::green_alert(){
static int green_alert_step = 0;



    if(green_alert_step<= 50)
    {
        green_alert_step+=1;
        for(int i=0;i<NUM_LEDS_SOMA; i++)
        {
            soma_leds[i].setRGB(0,4*green_alert_step,0);
        }
    }
    else
    {
        green_alert_step=0;
    }
}
void led_animations::no_alert(){
    for(int i =0; i<NUM_LEDS_SOMA; i++)
    {
        soma_leds[i] = CRGB::Black;
    }
}
void led_animations::scan(){
    static int scan_step = 0;
    for(int i =0; i<NUM_LEDS_SOMA; i++)
    {
    
        soma_leds[i] = CRGB::Black;
    }
    soma_leds[scan_step] = CRGB::White;
    scan_step+=1;
    if(scan_step > 15)
    {
        scan_step = 0;
    }
}