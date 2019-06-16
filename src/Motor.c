#include "Motor.h"

void SG90Setup(int Pin)
{
    pinMode(Pin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);  //clock at 50kHz (20us tick)
    pwmSetRange(1000); //range at 1000 ticks (20ms)
    pwmWrite(Pin, 75); // centerss
}

void DCRearSetup()
{
        //H-bridge gpios
        //Enables
        pinMode(EnA, OUTPUT);
        pinMode(EnB, OUTPUT);

        //PWM
        softPwmCreate(FBpwm, minValue, pwmRange);
        pinMode(FBpwm, PWM_OUTPUT);
        pwmSetMode(PWM_MODE_MS);
        pwmSetClock(dcClock);
        pwmWrite(FBpwm, 0);
}

void DCRear(Rear *Motor)
{

    switch (Motor->Dir)
    {
    case ('F'):
        digitalWrite(EnA, HIGH);
        digitalWrite(EnB, LOW);
        pwmWrite(FBpwm, Motor->Speed);
	printf("Mudou F");
        break;
    case ('B'):
        digitalWrite(EnA, LOW);
        if (Motor->Speed == 0)
        {
            digitalWrite(EnB, LOW);
            pwmWrite(FBpwm, 0);
        }
        else
        {
            digitalWrite(EnB, HIGH);
            pwmWrite(FBpwm, Motor->Speed);
        }
	printf("Mudou B");

        break;
    default:
        break;
    }
}
