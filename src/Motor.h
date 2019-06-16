#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include <wiringPi.h>
#include <softPwm.h>
 #include "UnrealEngine.h"

//Define GPIO Pin

// Orientation Servos
#define YAW 26
#define PITCH 23
//Servos PWM
#define sClock 384
#define sRange 1000

//Rear Motor H-bridge
#define EnA 23
#define EnB 24 
#define FBpwm 25
#define minValue 25
#define pwmRange 255
#define dcClock 384

//Front Motor
#define Left 20
#define Right 21
#define Center 17
#define MaxL 27
#define MaxR 22

void SG90Setup(int Pin);
void DCRearSetup();
void DCRear(Rear *Motor);
