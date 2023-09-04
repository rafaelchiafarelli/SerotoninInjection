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
  _scan,
  
  _point_win,
  _point_loose,
  _outer_cw,
  _outer_ccw,
  _inner_cw,
  _inner_ccw,
  _both_ccw,
  _both_cw,
  _follow_cw,
  _follow_ccw,

  AMOUNT
}animation_types;





#define NUM_LEDS_SEROTONIN 3
#define NUM_LEDS_POSTER 30
#define NUM_LEDS_HELM 7
#define NUM_LEDS_SOMA 16

#define NUM_LEDS_TRACE_OUTER 55
#define NUM_LEDS_TRACE_INNER 47
#define NUM_LEDS_TRACE_MARKS 27 

#define GAME_POINTS_MAX 11
#define GAME_MODE_MAX 4
#define GAME_LEVEL_MAX 5

#define SEROTONIN_PIN 13
#define POSTER_PIN 22
#define HELM_PIN 21
#define SOMA_PIN 12

#define INNER_PIN 13
#define OUTER_PIN 22
#define MARKS_PIN 21

typedef struct {
    int outer_step = -1;
    int inner_step = -1;
    int point_step = -1;
    int both_step = -1;
    int follow_step = -1; 
}hold_position;

class led_animations
{
private:
    /* data */
    CRGB serotonin_leds[NUM_LEDS_SEROTONIN];
    CRGB poster_leds[NUM_LEDS_POSTER];
    CRGB helm_leds[NUM_LEDS_HELM];
    CRGB soma_leds[NUM_LEDS_SOMA];
    CRGB trace_leds_outer[NUM_LEDS_TRACE_OUTER];
    CRGB trace_leds_inner[NUM_LEDS_TRACE_INNER];
    CRGB trace_leds_marks[NUM_LEDS_TRACE_MARKS];
    
    

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
    void scan();
    bool holding = false;
    hold_position to_hold;
    int outer_step = 0;
    void outer_cw(int white_one);
    void outer_ccw(int white_one);
    
    int inner_step = 0;
    void inner_ccw(int white_one);
    void inner_cw(int white_one);

    int point_step = 0;
    void point_loose();
    void point_win();

    int both_step = 0;
    void both_ccw(int white_one);
    void both_cw(int white_one);

    int follow_step = 0;
    void follow_ccw(int white_one);
    void follow_cw(int white_one);

    int mode_one_steps=0;
    void mode_one(int lives);

    int mode_two_steps=0;
    void mode_two(int lives);

    int mode_three_steps = 0;
    void mode_three(int lives);


    int sick_step = 0;    
    int filling_step = 0;
    int draining_step = 0;   
    int die_step = 0;       
    uint8_t poster_led_wake = 0;
    uint8_t helm_led_wake = 0;    
    uint8_t poster_led_sensor = 0;
    uint8_t helm_led_sensor = 0;    
    uint8_t poster_led_shift = 0;
    uint8_t helm_led_shift = 0;
    uint8_t poster_led_denial = 0;
    bool    direction_denial = true; 
    uint8_t poster_led_anger = 0;
    bool    direction_anger = true; 
    uint8_t poster_led_barganing = 0;
    bool direction_barganing = true;
    uint8_t poster_led_depression = 0;
    bool direction_depression = true;
    uint8_t poster_led_acceptance = 0;
    bool direction_acceptance = true;      
    void clear_marks();
    void set_points(int points);
    void paint_all(CRGB color);
    void trace_inner_leds_follow(int pos);
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

    #define INSTALLED_AMOUNT 6
    animation_types available_animations[INSTALLED_AMOUNT] = {_dead,_scan,_no_alert, _yellow_alert, _green_alert, _red_alert};
    String animations_names[INSTALLED_AMOUNT] = {"dead","scan","no_alert", "yellow_alert", "green_alert", "red_alert"};

    #elif SELECTED_DEVICE == 4

    #define INSTALLED_AMOUNT  11
    static const animation_types available_animations[INSTALLED_AMOUNT];//  {_dead, _point_loose, _point_win, _outer_cw, _outer_ccw, _inner_cw, _inner_ccw, _both_cw, _both_ccw, _follow_cw, _follow_ccw};
    static const String animations_names[INSTALLED_AMOUNT];//  {"dead","loose","win", "fora_sh", "fora_sah", "dentro_sh","dentro_sah", "ambos_sh", "ambos_sah", "seguido_sh", "seguido_sah"};

    #endif

    void restart(){
        sick_step = 0;    
        filling_step = 0;
        draining_step = 0;   
        die_step = 0;       
        poster_led_wake = 0;
        helm_led_wake = 0;    
        poster_led_sensor = 0;
        helm_led_sensor = 0;    
        poster_led_shift = 0;
        helm_led_shift = 0;
        poster_led_denial = 0;
        direction_denial = true; 
        poster_led_anger = 0;
        direction_anger = true; 
        poster_led_barganing = 0;
        direction_barganing = true;
        poster_led_depression = 0;
        direction_depression = true;
        poster_led_acceptance = 0;
        direction_acceptance = true;  

        outer_step = 0;
        inner_step = 0;
        point_step = 0;
        both_step = 0;
        follow_step = 0;

    }
    void animate(animation_types element, bool hold, int l_mode, int lives, int points);

    hold_position get_cur_pos(){
        hold_position hlt;
        hlt.both_step = both_step;
        hlt.inner_step = inner_step;
        hlt.follow_step = follow_step;
        hlt.outer_step = outer_step;
        hlt.point_step = point_step;
        return hlt;
    }
    void all_black();
    void all_green();
    void all_blue();
    void all_red();
    void all_white();

    led_animations();
    ~led_animations();
};



};
#endif