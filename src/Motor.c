#include "Motor.h"
// #include "UnrealEngine.h"

void SG90Setup(int Pin)
{
    // pinMode(Pin, PWM_OUTPUT);
    // pwmSetMode(PWM_MODE_MS);
    // pwmSetClock(384);  //clock at 50kHz (20us tick)
    // pwmSetRange(1000); //range at 1000 ticks (20ms)
    // pwmWrite(Pin, 75); // centers
}

void DCRearSetup()
{
    //     //H-bridge gpios
    //     //Enables
    //     pinMode(EnA, OUTPUT);
    //     pinMode(PiEnBn, OUTPUT);

    //     //PWM
    //     softPwmCreate(FBpwm, minValue, pwmRange);
    //     pinMode(FBpwm, PWM_OUTPUT);

    //         pwmSetMode(PWM_MODE_MS);
    //     pwmSetClock(dcClock);
}

// void DCRear(Rear *Motor)
// {

//     // switch (Motor->Dir)
//     // {
//     // case ('F'):
//     //     digitalWrite(EnA, HIGH);
//     //     digitalWrite(EnB, LOW);
//     //     pwmWrite(Pin, Motor->Speed);
//     //     break;
//     // case ('B'):
//     //     digitalWrite(EnA, LOW);
//     //     if (Motor->Speed == 0)
//     //     {
//     //         digitalWrite(EnB, LOW);
//     //         pwmWrite(Pin, 0);
//     //     }
//     //     else
//     //     {
//     //         digitalWrite(EnB, HIGH);
//     //         pwmWrite(Pin, Motor->Speed);
//     //     }

//     //     break;
//     // default:
//     //     break;
//     // }
// }
