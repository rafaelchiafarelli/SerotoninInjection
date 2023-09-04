#include "led_animations.h"

namespace animations{
const animation_types led_animations::available_animations[INSTALLED_AMOUNT] = {_dead, _point_loose, _point_win, _outer_cw, _outer_ccw, _inner_cw, _inner_ccw, _both_cw, _both_ccw, _follow_cw, _follow_ccw};
const String led_animations::animations_names[INSTALLED_AMOUNT] = {"dead","loose","win", "fora_sh", "fora_sah", "dentro_sh","dentro_sah", "ambos_sh", "ambos_sah", "seguido_sh", "seguido_sah"};

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
  #if SELECTED_DEVICE == 4
    FastLED.addLeds<NEOPIXEL, OUTER_PIN>(trace_leds_outer, NUM_LEDS_TRACE_OUTER);
    FastLED.addLeds<NEOPIXEL, INNER_PIN>(trace_leds_inner, NUM_LEDS_TRACE_INNER);
    FastLED.addLeds<NEOPIXEL, MARKS_PIN>(trace_leds_marks, NUM_LEDS_TRACE_MARKS);
  #endif  
}
led_animations::~led_animations()
{
}

void led_animations::dead()
{

all_black();

}
void led_animations::animate(animation_types element, bool hold, int l_mode, int lives, int points)
{
  if(hold && !holding)
  {
    to_hold.both_step = both_step;
    to_hold.follow_step = follow_step;
    to_hold.inner_step = inner_step;
    to_hold.outer_step = outer_step;
    holding = true;
  }

  if(!hold)
  {
    holding = false;
    to_hold.both_step = -1;
    to_hold.follow_step = -1;
    to_hold.inner_step = -1;
    to_hold.outer_step = -1;
  }

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
    case _point_loose:
    point_loose();
    break;
    case _point_win:
    point_win();
    break;
    case _inner_ccw:
    inner_ccw(to_hold.inner_step);
    break;
    case _inner_cw:
    inner_cw(to_hold.inner_step);
    break;
    case _outer_ccw:
    outer_ccw(to_hold.outer_step);
    break;
    case _outer_cw:
    outer_cw(to_hold.outer_step);
    break;
    case _both_ccw:
    both_ccw(to_hold.both_step);
    break;
    case _both_cw:
    both_cw(to_hold.both_step);
    break;
    case _follow_ccw:
    follow_ccw(to_hold.follow_step);
    break;
    case _follow_cw:
    follow_cw(to_hold.follow_step);
    break;
    default:
      break;
    }
    clear_marks();
    switch (l_mode)
    {

    case 0:
        mode_one(lives);
      break;
    case 1:
        mode_two(lives);
      break;
    case 2:
        mode_three(lives);
      break;  
    case 3:
        mode_one(lives);
        mode_two(lives);
        mode_three(lives);
      break;  
    default:
      break;
    }
    set_points(points);
FastLED.show();
}

void led_animations::all_black(){
  paint_all(CRGB::Black);
}
void led_animations::all_green(){
  paint_all(CRGB::Green);
}
void led_animations::all_blue(){
  paint_all(CRGB::Blue);
}
void led_animations::all_red(){
  paint_all(CRGB::Red);
}
void led_animations::all_white(){
  paint_all(CRGB::White);
}

void led_animations::paint_all(CRGB color){
  for(int i =0; i<NUM_LEDS_SEROTONIN;i++)
  {
    serotonin_leds[i] = color;
  }
  
  for(int i=0;i<NUM_LEDS_SOMA; i++)
  {
    soma_leds[i] = color;
  }
  
  for(int i=0;i<NUM_LEDS_HELM; i++)
  {
    helm_leds[i] = color;
  }
  
  for(int i=0;i<NUM_LEDS_POSTER;i++)
  {
    poster_leds[i] = color;
  }

  for(int i=0;i<NUM_LEDS_TRACE_OUTER;i++)
  {
    trace_leds_outer[i] = color;
  }


  for(int i=0;i<NUM_LEDS_TRACE_INNER;i++)
  {
    trace_leds_inner[i] = color;
  }
}


};