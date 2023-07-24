#include "led_animations.h"

using namespace animations;
/**
    CRGB poster_leds[NUM_LEDS_POSTER];
    CRGB helm_leds[NUM_LEDS_HELM];
 * 
 */
void led_animations::wakeup(){
    static uint8_t poster_led_wake = 0;
    static uint8_t helm_led_wake = 0;

    poster_leds[poster_led_wake] = CRGB::White;
    if(poster_led_wake<= NUM_LEDS_POSTER)
    {
        poster_led_wake+=1;
    }

    helm_leds[helm_led_wake] = CRGB::White;
    if(helm_led_wake <= NUM_LEDS_HELM)
    {
        helm_led_wake+=1;
    }
}
void led_animations::sensor(){
    static uint8_t poster_led_sensor = 0;
    static uint8_t helm_led_sensor = 0;

    poster_leds[poster_led_sensor] = CRGB::White;
    if(poster_led_sensor<= NUM_LEDS_POSTER)
    {
        poster_led_sensor+=1;
    }
    else
    {
        poster_led_sensor=0;
    }

    helm_leds[helm_led_sensor] = CRGB::White;
    if(helm_led_sensor <= NUM_LEDS_HELM)
    {
        helm_led_sensor+=1;
    }
    else
    {
        helm_led_sensor=0;
    }
}


void led_animations::shift(){
    static uint8_t poster_led_shift = 0;
    static uint8_t helm_led_shift = 0;

    poster_leds[poster_led_shift] = CRGB::Black;
    if(poster_led_shift<= NUM_LEDS_POSTER)
    {
        poster_led_shift+=1;
        poster_leds[poster_led_shift] = CRGB::White;
    }
    else
    {
        poster_led_shift=0;
    }

    helm_leds[helm_led_shift] = CRGB::Black;
    if(helm_led_shift <= NUM_LEDS_HELM)
    {
        helm_led_shift+=1;
        helm_leds[helm_led_shift] = CRGB::White;
    }
    else
    {
        helm_led_shift=0;
    }
}

void led_animations::denial(){
    static uint8_t poster_led_denial = 0;
    static bool direction = true;
    if(direction)
    {
        poster_led_denial+=1;
        if(poster_led_denial>15)
        {
            direction=!direction;
        }
    }
    else
    {
        poster_led_denial-=1;
        if(poster_led_denial == 0)
        {
            direction=!direction;
        }
    }
    for(int i=0;i<6; i++)
    {
        poster_leds[i].setRGB(5*poster_led_denial,5*poster_led_denial,0);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(5*poster_led_denial,5*poster_led_denial,0);
    }


}

void led_animations::anger(){
    static uint8_t poster_led_denial = 0;
    static bool direction = true;
    if(direction)
    {
        poster_led_denial+=1;
        if(poster_led_denial>15)
        {
            direction=!direction;
        }
    }
    else
    {
        poster_led_denial-=1;
        if(poster_led_denial == 0)
        {
            direction=!direction;
        }
    }
    for(int i=6;i<12; i++)
    {
        poster_leds[i].setRGB(5*poster_led_denial,0,0);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(5*poster_led_denial,0,0);
    }

}

void led_animations::barganing(){
    static uint8_t poster_led_denial = 0;
    static bool direction = true;
    if(direction)
    {
        poster_led_denial+=1;
        if(poster_led_denial>15)
        {
            direction=!direction;
        }
    }
    else
    {
        poster_led_denial-=1;
        if(poster_led_denial == 0)
        {
            direction=!direction;
        }
    }
    for(int i=12;i<18; i++)
    {
        poster_leds[i].setRGB(0,5*poster_led_denial,0);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(0,5*poster_led_denial,0);
    }

}

void led_animations::depression(){
    static uint8_t poster_led_denial = 0;
    static bool direction = true;
    if(direction)
    {
        poster_led_denial+=1;
        if(poster_led_denial>15)
        {
            direction=!direction;
        }
    }
    else
    {
        poster_led_denial-=1;
        if(poster_led_denial == 0)
        {
            direction=!direction;
        }
    }
    for(int i=18;i<24; i++)
    {
        poster_leds[i].setRGB(5*poster_led_denial,0,5*poster_led_denial);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(5*poster_led_denial,0,5*poster_led_denial);
    }

}

void led_animations::acceptance(){
    static uint8_t poster_led_denial = 0;
    static bool direction = true;
    if(direction)
    {
        poster_led_denial+=1;
        if(poster_led_denial>15)
        {
            direction=!direction;
        }
    }
    else
    {
        poster_led_denial-=1;
        if(poster_led_denial == 0)
        {
            direction=!direction;
        }
    }
    for(int i=24;i<30; i++)
    {
        poster_leds[i].setRGB(0,0,5*poster_led_denial);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(0,0,5*poster_led_denial);
    }

}
