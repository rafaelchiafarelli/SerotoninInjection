#include "led_animations.h"

using namespace animations;

/*
        outer_step = 0;
        inner_step = 0;
        point_step = 0;
        both_step = 0;
        follow_step = 0;

*/

void led_animations::point_loose(){
    switch(point_step)
    {
        case 0:
            all_red();
        break;
            case 15:
            all_black();
        break;
            case 30:
            all_red();
        break;
            case 45:
            all_black();
        break;
            case 60:
            all_red();
        break;
            case 75:
            all_black();
        break;
            case 90:
            all_red();
        break;
            case 105:
            all_black();
        break;
            case 120:
            all_red();
        break;
    }
    point_step+=1;
    if(point_step> 135)
    {
        point_step = 0;
    }
}
void led_animations::point_win(){

    switch(point_step)
    {
        case 0:
            all_green();
        break;
            case 15:
            all_black();
        break;
            case 30:
            all_green();
        break;
            case 45:
            all_black();
        break;
            case 60:
            all_green();
        break;
            case 75:
            all_black();
        break;
            case 90:
            all_green();
        break;
            case 105:
            all_black();
        break;
            case 120:
            all_green();
        break;
    }
    point_step+=1;
    if(point_step> 135)
    {
        point_step = 0;
    }

}
void led_animations::outer_ccw(int white_one){
    all_black();

    trace_leds_outer[outer_step] = CRGB::Blue;
    if(white_one>=0)
    {
        trace_leds_outer[white_one] = CRGB::White;
    }

    outer_step+=1;
    if(outer_step >= NUM_LEDS_TRACE_OUTER)
    {
        outer_step = 0;
    }   

}
void led_animations::outer_cw(int white_one){
    all_black();

    outer_step-=1;
    if(outer_step < 0)
    {
        outer_step = NUM_LEDS_TRACE_OUTER-1;
    }
    trace_leds_outer[outer_step] = CRGB::Blue;
    if(white_one>=0)
    {
        trace_leds_outer[white_one] = CRGB::White;
    }
 
}
void led_animations::inner_ccw(int white_one){
    all_black();

    inner_step-=1;
    if(inner_step < 0)
    {
        inner_step =  NUM_LEDS_TRACE_INNER;
    }
    trace_leds_inner[inner_step] = CRGB::Blue;   
    if(white_one>=0)
    {
        trace_leds_inner[white_one] = CRGB::White;
    }

}
void led_animations::inner_cw(int white_one){
    all_black();

    trace_leds_inner[inner_step] = CRGB::Blue;
    inner_step+=1;
    if(inner_step >= NUM_LEDS_TRACE_INNER)
    {
        inner_step = 0;
    }
    if(white_one>=0)
    {
        trace_leds_inner[white_one] = CRGB::White;
    }
}

void led_animations::both_ccw(int white_one){
    all_black();
    
    trace_leds_outer[outer_step] = CRGB::Blue;
    outer_step+=1;
    if(outer_step >= NUM_LEDS_TRACE_OUTER)
    {
        outer_step = 0;
    }

    inner_step-=1;
    if(inner_step < 0)
    {
        inner_step =  NUM_LEDS_TRACE_INNER -1 ;
    }
    trace_leds_inner[inner_step] = CRGB::Blue;   
    
    if(white_one>=0)
    {
        trace_leds_outer[white_one] = CRGB::White;
    }
}
void led_animations::both_cw(int white_one){
    all_black();

    outer_step-=1;
    if(outer_step < 0)
    {
        outer_step = NUM_LEDS_TRACE_OUTER-1;
    }
    trace_leds_outer[outer_step] = CRGB::Blue;

    trace_leds_inner[inner_step] = CRGB::Blue;
    inner_step+=1;
    if(inner_step >= NUM_LEDS_TRACE_INNER)
    {
        inner_step = 0;
    }
    
    if(white_one>=0)
    {
        trace_leds_outer[white_one] = CRGB::White;
    }
}


void led_animations::trace_inner_leds_follow(int pos)
{
    switch(pos)
    {
        case 0:
            trace_leds_inner[45] = CRGB::White;
        break;
        case 1:
            trace_leds_inner[44] = CRGB::White;
        break;
        case 2:
            trace_leds_inner[43] = CRGB::White;
        break;
        case 3:
            trace_leds_inner[42] = CRGB::White;
        break;
        case 4:
            trace_leds_inner[41] = CRGB::White;
        break;
        case 5:
            trace_leds_inner[40] = CRGB::White;
        break;
        case 6:
            trace_leds_inner[39] = CRGB::White;
        break;
        case 7:
            trace_leds_inner[39] = CRGB::White;
        break;
        case 8:
            trace_leds_inner[38] = CRGB::White;
        break;
        case 9:
            trace_leds_inner[37] = CRGB::White;
        break;
        case 10:
            trace_leds_inner[37] = CRGB::White;
        break;
        case 11:
            trace_leds_inner[36] = CRGB::White;
        break;
        case 12:
            trace_leds_inner[35] = CRGB::White;
        break;
        case 13:
            trace_leds_inner[34] = CRGB::White;
        break;
        case 14:
            trace_leds_inner[33] = CRGB::White;
        break;
        case 15:
            trace_leds_inner[32] = CRGB::White;
        break;
        case 16:
            trace_leds_inner[31] = CRGB::White;
        break;
        case 17:
            trace_leds_inner[30] = CRGB::White;
        break;
        case 18:
            trace_leds_inner[29] = CRGB::White;
        break;
        case 19:
            trace_leds_inner[29] = CRGB::White;
        break;
        case 20:
            trace_leds_inner[28] = CRGB::White;
        break;
        case 21:
            trace_leds_inner[27] = CRGB::White;
        break;
        case 22:
            trace_leds_inner[26] = CRGB::White;
        break;
        case 23:
            trace_leds_inner[25] = CRGB::White;
        break;
        case 24:
            trace_leds_inner[24] = CRGB::White;
        break;
        case 25:
            trace_leds_inner[23] = CRGB::White;
        break;
        case 26:
            trace_leds_inner[23] = CRGB::White;
        break;
        case 27:
            trace_leds_inner[22] = CRGB::White;
        break;
        case 28:
            trace_leds_inner[21] = CRGB::White;
        break;
        case 29:
            trace_leds_inner[21] = CRGB::White;
        break;
        case 30:
            trace_leds_inner[20] = CRGB::White;
        break;
        case 31:
            trace_leds_inner[19] = CRGB::White;
        break;
        case 32:
            trace_leds_inner[18] = CRGB::White;
        break;
        case 33:
            trace_leds_inner[17] = CRGB::White;
        break;
        case 34:
            trace_leds_inner[16] = CRGB::White;
        break;
        case 35:
            trace_leds_inner[15] = CRGB::White;
        break;
        case 36:
            trace_leds_inner[15] = CRGB::White;
        break;
        case 37:
            trace_leds_inner[14] = CRGB::White;
        break;
        case 38:
            trace_leds_inner[13] = CRGB::White;
        break;
        case 39:
            trace_leds_inner[12] = CRGB::White;
        break;
        case 40:
            trace_leds_inner[11] = CRGB::White;
        break;
        case 41:
            trace_leds_inner[10] = CRGB::White;
        break;
        case 42:
            trace_leds_inner[10] = CRGB::White;
        break;
        case 43:
            trace_leds_inner[9] = CRGB::White;
        break;
        case 44:
            trace_leds_inner[8] = CRGB::White;
        break;
        case 45:
            trace_leds_inner[7] = CRGB::White;
        break;
        case 46:
            trace_leds_inner[6] = CRGB::White;
        break;
        case 47:
            trace_leds_inner[5] = CRGB::White;
        break;
        case 48:
            trace_leds_inner[4] = CRGB::White;
        break;
        case 50:
            trace_leds_inner[3] = CRGB::White;
        break;
        case 51:
            trace_leds_inner[2] = CRGB::White;
        break;
        case 52:
            trace_leds_inner[1] = CRGB::White;
        break;
        case 53:
            trace_leds_inner[0] = CRGB::White;
        break;
        case 54:
            trace_leds_inner[46] = CRGB::White;
        break;

    }
}

void led_animations::follow_ccw(int white_one){
    follow_step+=1;
    
    if(follow_step >= NUM_LEDS_TRACE_OUTER)
    {
        follow_step = 0;
    }
    all_black();

    trace_leds_outer[follow_step] = CRGB::White;
    trace_inner_leds_follow(follow_step);
    if(white_one >=0)
    {
        trace_leds_outer[white_one] = CRGB::White;
        trace_inner_leds_follow(white_one);
    }

}


void led_animations::follow_cw(int white_one){
    follow_step-=1;
    
    if(follow_step <= 0)
    {
        follow_step =  NUM_LEDS_TRACE_OUTER-1;
    }
    all_black();
    trace_leds_outer[follow_step] = CRGB::White;
    trace_inner_leds_follow(follow_step);    
    if(white_one >=0)
    {
        trace_leds_outer[white_one] = CRGB::White;
        trace_inner_leds_follow(white_one);
    }
}

void led_animations::mode_one(int lives){
    trace_leds_marks[MODE_THREE_INDICATOR] = CRGB::Black;
    trace_leds_marks[MODE_TWO_INDICATOR] = CRGB::Black;
    trace_leds_marks[MODE_ONE_INDICATOR] = CRGB::White;    

    if(mode_one_steps >=0 && mode_one_steps<=MODE_STEPS_COUNT/2)
    {
        for(int i=MODE_ONE_LED_START + NUMBER_OF_STARTING_LIVES -1; i> MODE_ONE_LED_START; i--){
        trace_leds_marks[i] = CRGB::White;    
        }
    }    
    mode_one_steps+=1;
    if(mode_one_steps>MODE_STEPS_COUNT)
    {
        mode_one_steps = 0;
    }


}


void led_animations::mode_two(int lives){

    
    trace_leds_marks[MODE_THREE_INDICATOR] = CRGB::Black;
    trace_leds_marks[MODE_TWO_INDICATOR] = CRGB::White;
    trace_leds_marks[MODE_ONE_INDICATOR] = CRGB::Black;
    
    if(mode_two_steps >=0 && mode_two_steps<=MODE_STEPS_COUNT/2)
    {
        for(int i= MODE_TWO_LED_START+NUMBER_OF_STARTING_LIVES-1; i>MODE_TWO_LED_START; i--){
        trace_leds_marks[i] = CRGB::White;    
        }
    }
    mode_two_steps+=1;
    if(mode_two_steps>MODE_STEPS_COUNT)
    {
        mode_two_steps = 0;
    }
}

void led_animations::mode_three(int lives){
    trace_leds_marks[MODE_THREE_INDICATOR] = CRGB::White;
    trace_leds_marks[MODE_TWO_INDICATOR] = CRGB::Black;
    trace_leds_marks[MODE_ONE_INDICATOR] = CRGB::Black;
    if(mode_three_steps >=0 && mode_three_steps<=MODE_STEPS_COUNT/2)
    {
        for(int i=MODE_THREE_LED_START+NUMBER_OF_STARTING_LIVES; i> MODE_THREE_LED_START; i--){
        trace_leds_marks[i] = CRGB::White;    
        }
    }
    mode_three_steps+=1;
    if(mode_three_steps>MODE_STEPS_COUNT)
    {
        mode_three_steps = 0;
    }    
}

void led_animations::set_points(int points)
{
    for(int i=0; i< points; i++){
        trace_leds_marks[i] = CRGB::White;    
        }
}

void led_animations::clear_marks(){
    for(int i=0; i< NUM_LEDS_TRACE_MARKS; i++){
        trace_leds_marks[i] = CRGB::Black;    
        }
}