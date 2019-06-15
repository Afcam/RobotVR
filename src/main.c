#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "UDP.h"
#include "UnrealEngine.h"

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
    //Strings que armazenam o valor dos ângulos
    char cPitch[13], cYaw[13];

    int i;
    int a = 0;

    char *menssage;
    Axes *Rot ;

    while (1)
    {
        menssage = ReadUDP(u_Servo);
        Rot = UDP_30000(menssage);
        printf("++ %f %f %f \n",Rot->Pich,Rot->Yaw,Rot->Yaw);

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
