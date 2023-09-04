#ifndef GAME_PLAY_H
#define GAME_PLAY_H
#include "io_handler.h"
#include "led_animations.h"
#include "config.h"

typedef enum {
    mode_0,
    mode_1,
    mode_2,/*  */
    invalid

}game_mode;

typedef enum
{
    waiting_for_selection,
    selected_position,
    win,
    loose,
}game_state;

class GamePlay
{   
    private:
        int points = 0;
        int lives = NUMBER_OF_STARTING_LIVES;

        int dificulty = 0;
        game_state state = waiting_for_selection;
        game_mode g_mode = mode_0;
        int time_counter = 0; 
        animations::hold_position rec_pos;
        animations::animation_types cur_animation = animations::animation_types::_dead;
        void change_mode();
        void play(animations::hold_position cur_pos);
        void victory();
        void defeat();
        animations::animation_types mode_to_animetion();
        void reset(game_mode m)
        {
            g_mode = m;
            state = waiting_for_selection;
            dificulty = 0;
            animations::hold_position pos;
            rec_pos = pos;
            time_counter = 0;
        }

    public:
    void to_string();
    bool get_hold(){
        if(state == selected_position)
        {
            return true;
        }
        return false;
    }

    int get_points(){return points;}
    int get_mode(){return (int)g_mode;}
    int get_lives(){return lives;}
    int get_dificulty(){
        return MAX_DIFICULTY - points;

    }
        GamePlay(){};
        animations::animation_types game_handler(action act, animations::hold_position cur_pos);
};

#endif