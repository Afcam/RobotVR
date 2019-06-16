#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "Motor.h"

void SG90Setup(int Pin)
{
    // pinMode(Pin, PWM_OUTPUT);
    // pwmSetMode(PWM_MODE_MS);
    // pwmSetClock(384);  //clock at 50kHz (20us tick)
    // pwmSetRange(1000); //range at 1000 ticks (20ms)
    // pwmWrite(Pin, 75); // centers
}