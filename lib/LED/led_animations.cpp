#include "led_animations.h"

namespace animations{
led_animations::led_animations(){
    #if SELECTED_DEVICE == 2
    FastLED.addLeds<NEOPIXEL, SEROTONIN_PIN>(serotonin_leds, NUM_LEDS_SEROTONIN);
  #endif
  #if SELECTED_DEVICE == 1
    FastLED.addLeds<NEOPIXEL, POSTER_PIN>(poster_leds, NUM_LEDS_POSTER);
    FastLED.addLeds<NEOPIXEL, HELM_PIN>(helm_leds, NUM_LEDS_HELM);
  #endif
  #if SELECTED_DEVICE == 3
    FastLED.addLeds<NEOPIXEL, SOMA_PIN>(soma_leds, NUM_LEDS_SOMA);
  #endif
}
led_animations::~led_animations()
{
}

void led_animations::dead(){

  
  for(int i =0; i<NUM_LEDS_SEROTONIN;i++)
  {
    serotonin_leds[i] = CRGB::Black;
  }
  for(int i=0;i<NUM_LEDS_SOMA; i++)
  {
    soma_leds[i] = CRGB::Black;
  }
  for(int i=0;i<NUM_LEDS_HELM; i++)
  {
    helm_leds[i] = CRGB::Black;
  }
  for(int i=0;i<NUM_LEDS_POSTER;i++)
  {
    poster_leds[i] = CRGB::Black;
  }

}
void led_animations::animate(animation_types element)
{
  Serial.print("got here with: ");
  Serial.println((int)element);
switch (element)
    {
    case _dead:
    {
      dead();
    }
    break;
    case _sick:
    {
      sick();
    }
    break;
    case _filling:
    {
      filling();
    }
    break;
    case _draining:
      draining();
      break;
    case _full:
    full();
      break;
    case _die:
    die();
    break;
    case _wakeup:
    wakeup();
    break;
    case _sensor:
    sensor();
    break;
    case _shift:
    shift();
    break;
    case _denial:
    denial();
    break;

    case _anger:
    anger();
    break;
    case _barganing:
    barganing();
    break;
    case _depression:
    depression();
    break;
    case _acceptance:
    acceptance();
    break;
    case _yellow_alert:
    yellow_alert();
    break;
    case _green_alert:
    green_alert();
    break;
    case _red_alert:
    red_alert();
    break;
    case _no_alert:
    no_alert();
    break;
    case _scan:
    scan();
    break;
                        
    default:
      break;
    }
FastLED.show();
}

};