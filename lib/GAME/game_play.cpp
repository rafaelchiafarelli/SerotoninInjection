#include "game_play.h"

animations::animation_types GamePlay::mode_to_animetion()
{
    if(g_mode == mode_0)
    {
        return animations::animation_types::_outer_cw;
    }
    if(g_mode == mode_1)
    {
        return animations::animation_types::_inner_ccw;
    }
    if(g_mode == mode_2)
    {
        return animations::animation_types::_follow_cw;
    }
}
void GamePlay::to_string(){
    char str[255];
    sprintf(str, "lives: %d, poinst: %d, state: %d, dificulty: %d, g_mode: %d, time_counter:%d rec_pos: {%d,%d,%d,%d,%d}, cur_animation%d",lives,points, state, dificulty, g_mode,time_counter, rec_pos.both_step, rec_pos.follow_step, rec_pos.inner_step, rec_pos.outer_step, rec_pos.point_step, animations::led_animations::animations_names[cur_animation]  );
    Serial.println(str);
}
animations::animation_types GamePlay::game_handler(action act, animations::hold_position cur_pos){

switch (state)
{
case waiting_for_selection:
    cur_animation = mode_to_animetion();
    switch (act)
    {
    case action::play:
        rec_pos = cur_pos;
        state = selected_position;
        break;
    case action::mode:
        change_mode();
        reset(g_mode);
        break;
    case action::no_action:
        break;
    }
    break;
case selected_position:
    cur_animation = mode_to_animetion();
    switch (act)
    {
    case action::play:
        play(cur_pos);
        break;
    case action::mode:
        change_mode();
        reset(g_mode);    
    break;
    case action::no_action:
        time_counter++;
        if(time_counter > MAX_DEAD_TIME)
        {
            time_counter = 0;
            defeat();
        }
    break;
    
    default:
        break;
    }
break;

case win:
    time_counter+=1;
    if(time_counter >= TIME_OF_WINNING_ANIMATION)
    {
        time_counter = 0;
        reset(g_mode);
    }
break;
case loose:
    time_counter+=1;
    if(time_counter >= TIME_OF_LOOSE_ANIMATION)
    {
        time_counter = 0;
        reset(g_mode);
    }
break;


default:
    break;
}
return cur_animation;
}

void GamePlay::change_mode(){
    points = 0;
    lives = NUMBER_OF_STARTING_LIVES;
    if(g_mode  >= mode_2 || mode < 0)
    {
        g_mode = mode_0;
    }
    else
    {
        g_mode = (game_mode) ((int)g_mode+1);
    }
}

/*
mode_0 --> out_cw
mode_1 --> inner_ccw
mode_2 --> follow_cw

*/

void GamePlay::play(animations::hold_position cur_pos){
    switch (g_mode)
    {
    case mode_0:
        if((cur_pos.outer_step >= rec_pos.outer_step -1 ) && (cur_pos.outer_step <= rec_pos.outer_step +1))
        {
            victory();
        }
        else
        {
            defeat();
        }
    break;
    case mode_1:
        if((cur_pos.inner_step >= rec_pos.inner_step -1 ) && (cur_pos.inner_step <= rec_pos.inner_step +1))
        {
            victory();
        }
        else
        {
            defeat();
        }
    break;
    case mode_2:
        if((cur_pos.follow_step >= rec_pos.follow_step -1 ) && (cur_pos.follow_step <= rec_pos.follow_step +1))
        {
            victory();
        }
        else
        {
            defeat();
        }
    break;                    
    default:
    break;
    }
}


void GamePlay::victory(){
    points++;
    state = win;
    cur_animation = animations::animation_types::_point_win;
    if(points >= MAX_POINTS)
    {
        change_mode();
    }
}

void GamePlay::defeat(){
    state = loose;
    cur_animation = animations::animation_types::_point_loose;
    lives-=1;
    if(lives<=0)
    {
        lives = NUMBER_OF_STARTING_LIVES;
        change_mode();
    }
}

