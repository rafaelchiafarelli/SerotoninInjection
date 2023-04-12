#ifndef LED_H
#define LED_H

typedef union
{
    unsigned char uc[4];
    unsigned int i;
} color;
class led
{
private:
    /* data */

public:
    color c;

    led(unsigned int r, unsigned int g, unsigned int b);
    ~led();
};

led::led(unsigned int r, unsigned int g, unsigned int b)
{
    c.uc[0] = 0xff & r;
    c.uc[1] = 0xff00 & g;
    c.uc[2] = 0xff0000 & b;
}

led::~led()
{
}

#endif