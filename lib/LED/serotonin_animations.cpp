#include "led_animations.h"
using namespace animations;

void led_animations::sick(){

      /* code */
      switch (sick_step)
      {
      case 0:
        /* code */
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Red;
        serotonin_leds[2] = CRGB::Red;

        break;
      case 1:
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Yellow;
        serotonin_leds[2] = CRGB::Red;        
        break;

      case 3:
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Yellow;
        serotonin_leds[2] = CRGB::Red;        
        break;

      case 5:
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Red;
        serotonin_leds[2] = CRGB::Red;
        break;
      case 7:
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Yellow;
        serotonin_leds[2] = CRGB::Red;   
        break;
      case 9:
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Red;
        serotonin_leds[2] = CRGB::Red;
        break;
      case 11:
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Yellow;
        serotonin_leds[2] = CRGB::Red;   
        break;        
      case 12:
        sick_step = 4;
        break;
      }
      sick_step+=1;
}
void led_animations::filling(){
  
      switch (filling_step)
      {
      case 0:
        /* code */
        serotonin_leds[0] = CRGB::Yellow;
        serotonin_leds[1] = CRGB::Black;
        serotonin_leds[2] = CRGB::Black;
        break;
      case 1:
        serotonin_leds[0] = CRGB::Green;
        serotonin_leds[1] = CRGB::Yellow;
        serotonin_leds[2] = CRGB::Black;
        break;
      case 3:
        serotonin_leds[0] = CRGB::Green;
        serotonin_leds[1] = CRGB::Green;
        serotonin_leds[2] = CRGB::Yellow;
        
        break;
      case 5:
        serotonin_leds[0] = CRGB::Green;
        serotonin_leds[1] = CRGB::Green;
        serotonin_leds[2] = CRGB::Green;
        
        break;        
      case 7:
        serotonin_leds[0] = CRGB::Black;
        serotonin_leds[1] = CRGB::Black;
        serotonin_leds[2] = CRGB::Black;
        
        break;         
      case 9:
        serotonin_leds[0] = CRGB::Green;
        serotonin_leds[1] = CRGB::Green;
        serotonin_leds[2] = CRGB::Green;
        
        break;         
      case 11:
        serotonin_leds[0] = CRGB::Black;
        serotonin_leds[1] = CRGB::Black;
        serotonin_leds[2] = CRGB::Black;
        
        break;         
      case 13:
        serotonin_leds[0] = CRGB::Green;
        serotonin_leds[1] = CRGB::Green;
        serotonin_leds[2] = CRGB::Green;
        
        break;            
      case 14:
        filling_step = 12;
        break;
      }
      filling_step+=1;
}
void led_animations::draining(){
      /* code */

        switch (draining_step)
        {
        case 0:
          /* code */
          serotonin_leds[0] = CRGB::Green;
          serotonin_leds[1] = CRGB::Green;
          serotonin_leds[2] = CRGB::Green;

          break;
        case 3:
          serotonin_leds[0] = CRGB::Green;
          serotonin_leds[1] = CRGB::Green;
          serotonin_leds[2] = CRGB::Yellow;
          break;
        case 6:
          serotonin_leds[0] = CRGB::Green;
          serotonin_leds[1] = CRGB::Yellow;
          serotonin_leds[2] = CRGB::Yellow;
          break;
        case 9:
          serotonin_leds[0] = CRGB::Yellow;
          serotonin_leds[1] = CRGB::Yellow;
          serotonin_leds[2] = CRGB::Yellow;
          break;
        case 12:
          serotonin_leds[0] = CRGB::Yellow;
          serotonin_leds[1] = CRGB::Yellow;
          serotonin_leds[2] = CRGB::Yellow;
          break;
        case 15:
          serotonin_leds[0] = CRGB::Yellow;
          serotonin_leds[1] = CRGB::Yellow;
          serotonin_leds[2] = CRGB::Red;
          break;          
        case 18:
          serotonin_leds[0] = CRGB::Yellow;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          
          break;         
        case 21:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          
          break;             
        case 24:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Black;
          
          break;             
        case 27:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
          break;             
        case 30:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
          break;             
        case 33:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          
          break;
        case 36:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
          break;             
        case 39:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          
          break;    
        case 40:
          draining_step = 29;
          break;
        }
        draining_step+=1;
      
}
void led_animations::full(){
  serotonin_leds[0] = CRGB::Green;
  serotonin_leds[1] = CRGB::Green;
  serotonin_leds[2] = CRGB::Yellow;
  
}
void led_animations::die(){

        switch (die_step)
        {
        case 0:
          /* code */
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;

          break;
        case 3:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 6:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 9:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;
        case 12:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Red;
          break;
        case 15:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;          
        case 18:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Black;
          break;         
        case 21:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
        break;
        case 24:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;         
        case 27:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
        break;
        case 30:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Red;
          break;         
        case 33:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
        break;
        case 36:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Black;
          break;         
        case 39:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
        break;
        case 42:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          break;         
        case 45:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
        break;
        case 47:
          serotonin_leds[0] = CRGB::Red;
          serotonin_leds[1] = CRGB::Red;
          serotonin_leds[2] = CRGB::Red;
          break;         
        case 49:
          serotonin_leds[0] = 0x1f0000;
          serotonin_leds[1] = 0x1f0000;
          serotonin_leds[2] = 0x1f0000;
          break;         
        case 50:
          serotonin_leds[0] = 0x800000;
          serotonin_leds[1] = 0x800000;
          serotonin_leds[2] = 0x800000;
          break;         
        case 51:
          serotonin_leds[0] = 0x400000;
          serotonin_leds[1] = 0x400000;
          serotonin_leds[2] = 0x400000;
          break;         
        case 52:
          serotonin_leds[0] = 0x200000;
          serotonin_leds[1] = 0x200000;
          serotonin_leds[2] = 0x200000;
          break;                                                 
        case 53:
          serotonin_leds[0] = 0x100000;
          serotonin_leds[1] = 0x100000;
          serotonin_leds[2] = 0x100000;
          break;            
        case 54:
          serotonin_leds[0] = CRGB::Black;
          serotonin_leds[1] = CRGB::Black;
          serotonin_leds[2] = CRGB::Black;
          
        break;                                        
        case 55:
          die_step = 53;
        break;
        }
        
        die_step+=1;

}
