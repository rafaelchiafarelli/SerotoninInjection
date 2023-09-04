#include "io_handler.h"
#include "Arduino.h"


void io_handler::handler(){
    digital_io(play_btn, play_pin_state);
    digital_io(mode_btn, mode_pin_state);

}

action io_handler::get_action(){

    if((mode_pin_state == edge_up  ) && (play_pin_state == edge_down || play_pin_state == off))
        return mode;
    if((mode_pin_state == edge_down || mode_pin_state == off ) && (play_pin_state == edge_up))
        return play;
    return no_action;        
}

void io_handler::digital_io(int pin_number, btn_states &btn_state)
{
    if(digitalRead(pin_number) == ACTIVE)
      {

            switch(btn_state)
            {
                case on:
                    //nothing to do
                    btn_state = on;
                    break;
                case off:
                    //edge_up detected
                    
                    
                    btn_state = edge_up;
                break;
                case edge_up:
                    btn_state = on;
                break;
                case edge_down:
                    btn_state = edge_up;
                    break;
            }           
      }
      else
      {
            switch(btn_state)
            {
                case on:
                    btn_state = edge_down;
                    break;
                case off:
                    //nothing to do
                    btn_state = off;
                break;
                case edge_up:
                    btn_state = edge_down;
                break;
                case edge_down:
                    btn_state = off;
                    break;
            }           
      }
}