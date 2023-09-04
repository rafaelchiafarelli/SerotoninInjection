#ifndef IO_HANDLER_H
#define IO_HANDLER_H

typedef enum 
{
    mode,
    play,
    no_action
}action;

typedef enum
{
    on,
    off,
    edge_up,
    edge_down
}btn_states;

#define play_btn 33
#define mode_btn 32
#define ACTIVE 0
#define NOT_ACTIVE 1
class io_handler
{
    private:
        btn_states mode_pin_state = off;
        btn_states play_pin_state = off;
        void digital_io(int pin_number, btn_states &btn_state);
    public:
        void handler();
        action get_action();
};
#endif