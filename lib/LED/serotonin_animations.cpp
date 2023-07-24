#include "led_animations.h"
using namespace animations;

void led_animations::sick(){
static int sick_step = 0;
      /* code */
      switch (sick_step)
      {
      case 0:
        /* code */
        serotonin_leds[0] = CRGB::Black;
        serotonin_leds[1] = CRGB::Black;
        serotonin_leds[2] = CRGB::Black;

        break;
      case 1:
        serotonin_leds[0] = CRGB::Green;
        break;

      case 3:
        serotonin_leds[1] = CRGB::Green;
        break;

      case 5:
        serotonin_leds[2] = CRGB::Green;
        break;

      case 6:
        sick_step = 5;
        break;
        default:
        sick_step = 0;
        break;
      }
      FastLED.show();
      sick_step = 0;
}
void led_animations::filling(){
  static int filling_step = 0;
      switch (filling_step)
      {
      case 0:
        /* code */
        serotonin_leds[0] = CRGB::Black;
        serotonin_leds[1] = CRGB::Black;
        serotonin_leds[2] = CRGB::Black;
        break;
      case 1:
        serotonin_leds[0] = CRGB::Red;
        serotonin_leds[1] = CRGB::Red;
        serotonin_leds[2] = CRGB::Black;
        break;
      case 3:
        serotonin_leds[0] = CRGB::Red;
        serotonin_leds[1] = CRGB::Black;
        serotonin_leds[2] = CRGB::Black;
        
        break;
      default:
        filling_step = 0;
        break;
      }
      FastLED.show();
      filling_step+=1;
}
void led_animations::draining(){
      /* code */
static int draining_step = 0;   
        switch (draining_step)
        {
        case 0:
          /* code */
          serotonin_leds[0] = CRGB::Green;
          serotonin_leds[1] = CRGB::Green;
          serotonin_leds[2] = CRGB::Yellow;

          break;
        case 1:
          serotonin_leds[0] = CRGB::Green;
          serotonin_leds[1] = CRGB::Yellow;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 3:
          serotonin_leds[0] = CRGB::Yellow;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Red;
          break;
        case 4:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          break;
        case 5:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          break;
        case 6:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;          
        case 7:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          draining_step=5; 
          break;         
        default:
          draining_step = 0;              
        }
        FastLED.show();
        draining_step+=1;
      
}
void led_animations::full(){
  serotonin_leds[0] = CRGB::Green;
  serotonin_leds[1] = CRGB::Green;
  serotonin_leds[2] = CRGB::Green;
  FastLED.show();

}
void led_animations::die(){
static int die_step = 0;   
        switch (die_step)
        {
        case 0:
          /* code */
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;

          break;
        case 1:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 3:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 4:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 5:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          break;
        case 6:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;          
        case 7:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          break;         
        case 8:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          die_step = 7;
        break;
        default:
          die_step = 0;              
        }
        FastLED.show();
        die_step+=1;

}
