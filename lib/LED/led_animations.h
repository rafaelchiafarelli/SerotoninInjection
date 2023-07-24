#ifndef LED_H
#define LED_H
#include "config.hpp"
#include <FastLED.h>
#include <stdlib.h>
namespace animations{
typedef enum{
  _dead,
  _sick,
  _filling,
  _draining,
  _full,
  _die,
  _wakeup,
  _sensor,
  _shift,
  _denial,
  _anger,
  _barganing,
  _depression,
  _acceptance,
  _yellow_alert,
  _green_alert,
  _red_alert,
  _no_alert,
  AMOUNT
}animation_types;





#define NUM_LEDS_SEROTONIN 3
#define NUM_LEDS_POSTER 30
#define NUM_LEDS_HELM 7
#define NUM_LEDS_SOMA 16


#define SEROTONIN_PIN 13
#define POSTER_PIN 22
#define HELM_PIN 21
#define SOMA_PIN 12

class led_animations
{
private:
    /* data */
    CRGB serotonin_leds[NUM_LEDS_SEROTONIN];
    CRGB poster_leds[NUM_LEDS_POSTER];
    CRGB helm_leds[NUM_LEDS_HELM];
    CRGB soma_leds[NUM_LEDS_SOMA];
    

    void dead();
    void sick();
    void filling();
    void draining();
    void full();
    void die();
    void wakeup();
    void sensor();
    void shift();
    void denial();
    void anger();
    void barganing();
    void depression();
    void acceptance();
    void red_alert();
    void yellow_alert();
    void green_alert();
    void no_alert();
public:
    #if SELECTED_DEVICE == 1

    #define INSTALLED_AMOUNT 10
    String animations_names[INSTALLED_AMOUNT] = {"dead","wakeup","sensor","shift", "denial", "anger", "barganing", "depression", "acceptance" };
    animation_types available_animations[INSTALLED_AMOUNT] = {_dead,_wakeup,_sensor,_shift, _denial, _anger, _barganing, _depression, _acceptance};

    #elif SELECTED_DEVICE == 2

    #define INSTALLED_AMOUNT 6   
    String animations_names[INSTALLED_AMOUNT] = {"dead","sick", "filling", "draining", "full", "die"};
    animation_types available_animations[INSTALLED_AMOUNT] = {_dead,_sick, _filling, _draining, _full, _die};

    #elif SELECTED_DEVICE == 3

    #define INSTALLED_AMOUNT 5
    animation_types available_animations[INSTALLED_AMOUNT] = {_dead,_no_alert, _yellow_alert, _green_alert, _red_alert};
    String animations_names[INSTALLED_AMOUNT] = {"dead","no_alert", "yellow_alert", "green_alert", "red_alert"};

    #endif

    void animate(animation_types element);
    led_animations();
    ~led_animations();
};



};
#endif