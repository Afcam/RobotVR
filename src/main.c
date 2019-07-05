#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include <wiringPi.h>
#include <softPwm.h>

#include "UDP.h"
#include "motor.h"
#include "UnrealEngine.h"

void *Orientation();
void *RearMotor();
void *FrontMotor();

// ========================================================
// Main
// ========================================================
int main()
{
    pthread_t th_Orientation;
    pthread_t th_Rear;
    pthread_t th_Front;

    // Initializes Wiring Pi
     if (wiringPiSetup() == -1)
     {
         fprintf(stdout, "oops: %s\n", strerror(errno));
         return 1;
     }

     pthread_create(&th_Orientation, NULL, Orientation, NULL);
     pthread_create(&th_Rear, NULL, RearMotor, NULL);
     pthread_create(&th_Front, NULL, FrontMotor, NULL);

    /* wait for thread to finish */
     pthread_join(th_Orientation, NULL);
     pthread_join(th_Rear, NULL);
     pthread_join(th_Front, NULL);

    return (0);
 }

 // ========================================================
// Orientation
// ========================================================
void *Orientation()
{
    UDP *udp_Orientation;
    Axes *AXIS;
    udp_Orientation = UDPSetup(30000);
    fflush(stdout);

    SG90Setup(YAW);
    SG90Setup(PITCH);

    for (;;)
    {
        AXIS = UEAxes(UDPRead(udp_Orientation));
        printf("++ %f %f \n", AXIS->Pich, AXIS->Yaw);
        pwmWrite(PITCH, AXIS->Pich);
        pwmWrite(YAW, AXIS->Yaw);
    }
}

// ========================================================
// DC Motors Rear
// ========================================================
void *RearMotor()
{
    pid_t pid;
    UDP *udp_Rear;
    Rear *Motor;
    DCRearSetup();
    udp_Rear = UDPSetup(30001);
    fflush(stdout);

    pid = fork();
    if (pid < 0)
    {
        printf("Erro!!!\n");
        exit(-1);
    }

    

    for (;;)
    {
        Motor = UERear(UDPRead(udp_Rear));
        printf("\n+Rear: %c %d \n", Motor->Dir, Motor->Speed);
        DCRear(Motor);
        delay(1);
    }
}
// ========================================================
// DC Motors Front
// ========================================================

void *FrontMotor()
{
    UDP *udp_Front;
    DCFrontSetup();
    udp_Front = UDPSetup(30002);
    fflush(stdout);
    char *msg;

    for (;;)
    {
        msg = UDPRead(udp_Front);
        printf("++ %s\n", msg);
        DCFront(msg);
        // delay(1);

    }
}

// ========================================================
// TRASH
// ========================================================
// pthread_t t_Servo;
// pthread_t t_Rear;
// pthread_t t_Front;
// printf("hello ");
// UDP *u_Servo;
// UDP *u_Rear;
// UDP *u_Front;

// u_Servo = InitUDP(30000);
// u_Rear = InitUDP(5001);
// u_Front = InitUDP(5002);
// fflush(stdout);

// wiringPiSetup();

// Normal(u_Servo);
// pthread_create(&t_Servo, NULL, Bosta, (void*)&u_Servo);
// pthread_join(Normal, NULL);
// pthread_join(Normal, NULL);
// pthread_create(&t_Rear, NULL, Normal, (void *)&u_Rear);
// pthread_create(&t_Front, NULL, Normal, (void *)&u_Front);
// while (1)
// {

// }

// void *conometro(void *var)
// {
//     // int *vari=var;
//     for(;;)
//     {
//     printf("\n==Timer: %d == \n",(int *)var);
//     sleep(3);
//     }
// }

// void *fteste()
// {
//     printf("Estoru na tread");
//     pthread_t teste;

//     int variavel;
//     // pthread_create(&te]ç9ste, NULL, conometro, variavel);

//     for(;;)
//     {
//         printf("\n Esperando... = ");
//         printf("%d",variavel);
//         variavel+=1;
//         sleep(1);
//     }
// }