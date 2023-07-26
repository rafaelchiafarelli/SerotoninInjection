#include "led_animations.h"

using namespace animations;
/**
    CRGB poster_leds[NUM_LEDS_POSTER];
    CRGB helm_leds[NUM_LEDS_HELM];
 * 
 */
void led_animations::wakeup(){


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

    if(direction_denial)
    {
        poster_led_denial+=1;
        if(poster_led_denial>15)
        {
            direction_denial=!direction_denial;
        }
    }
    else
    {
        poster_led_denial-=1;
        if(poster_led_denial == 0)
        {
            direction_denial=!direction_denial;
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

    if(direction_anger)
    {
        poster_led_anger+=1;
        if(poster_led_anger>15)
        {
            direction_anger=!direction_anger;
        }
    }
    else
    {
        poster_led_anger-=1;
        if(poster_led_anger == 0)
        {
            direction_anger=!direction_anger;
        }
    }
    for(int i=6;i<12; i++)
    {
        poster_leds[i].setRGB(5*poster_led_anger,0,0);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(5*poster_led_anger,0,0);
    }

}

void led_animations::barganing(){

    if(direction_barganing)
    {
        poster_led_barganing+=1;
        if(poster_led_barganing>15)
        {
            direction_barganing=!direction_barganing;
        }
    }
    else
    {
        poster_led_barganing-=1;
        if(poster_led_barganing == 0)
        {
            direction_barganing=!direction_barganing;
        }
    }
    for(int i=12;i<18; i++)
    {
        poster_leds[i].setRGB(0,5*poster_led_barganing,0);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(0,5*poster_led_barganing,0);
    }

}

void led_animations::depression(){

    if(direction_depression)
    {
        poster_led_depression+=1;
        if(poster_led_depression>15)
        {
            direction_depression=!direction_depression;
        }
    }
    else
    {
        poster_led_depression-=1;
        if(poster_led_depression == 0)
        {
            direction_depression=!direction_depression;
        }
    }
    for(int i=18;i<24; i++)
    {
        poster_leds[i].setRGB(5*poster_led_depression,0,5*poster_led_depression);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(5*poster_led_depression,0,5*poster_led_depression);
    }

}

void led_animations::acceptance(){

    if(direction_acceptance)
    {
        poster_led_acceptance+=1;
        if(poster_led_acceptance>15)
        {
            direction_acceptance=!direction_acceptance;
        }
    }
    else
    {
        poster_led_acceptance-=1;
        if(poster_led_acceptance == 0)
        {
            direction_acceptance=!direction_acceptance;
        }
    }
    for(int i=24;i<30; i++)
    {
        poster_leds[i].setRGB(0,0,5*poster_led_acceptance);
    }
    for(int i=0;i<NUM_LEDS_HELM; i++)
    {
        helm_leds[i].setRGB(0,0,5*poster_led_acceptance);
    }

}
