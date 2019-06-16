#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include <wiringPi.h>

#include "UDP.h"
#include "UnrealEngine.h"

//Define GPIO Pin
#define YAW 26
#define PITCH 23

void *Bosta(void *arg)
{
    UDP *udp = (UDP *)arg;

    char *menssage;
    // for (;;)
    // {
    printf("Na thread");
    menssage = ReadUDP(udp);
    // printf("%s", udp->addr_len);
    // sleep(1);
    // }
}

int main()
{
    pthread_t t_Servo;
    // pthread_t t_Rear;
    // pthread_t t_Front;
    // printf("hello ");
    UDP *u_Servo;
    // UDP *u_Rear;
    // UDP *u_Front;

    u_Servo = InitUDP(30000);
    // u_Rear = InitUDP(5001);
    // u_Front = InitUDP(5002);
    fflush(stdout);
    char *token;

    int i;
    int a = 0;

    char *menssage;
    Axes *Rot;

    pinMode(PITCH, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);  //clock at 50kHz (20us tick)
    pwmSetRange(1000); //range at 1000 ticks (20ms)

    pinMode(YAW, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(384);  //clock at 50kHz (20us tick)
    pwmSetRange(1000); //range at 1000 ticks (20ms)

    while (1)
    {
        menssage = ReadUDP(u_Servo);
        Rot = UDP_30000(menssage);
        printf("++ %f %f %f \n", Rot->Pich, Rot->Yaw, Rot->Yaw);
        pwmWrite(PITCH, 75);
        pwmWrite(YAW 75);
        // printf("%s", menssage);
        printf("%d", a);
        a++;
    }

    // Normal(u_Servo);
    // pthread_create(&t_Servo, NULL, Bosta, (void*)&u_Servo);
    // pthread_join(Normal, NULL);
    // pthread_join(Normal, NULL);
    // pthread_create(&t_Rear, NULL, Normal, (void *)&u_Rear);
    // pthread_create(&t_Front, NULL, Normal, (void *)&u_Front);
    // while (1)
    // {

    // }

    return (0);
}
