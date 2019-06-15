#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "SG90.h"

// int SG90_Server(char *buffer)
// {
//     char *token;

//     token = strtok(menssage, " ");
//     i = 0;
//     while (token != NULL)
//     {
//         if (token != NULL)
//         {
//             if (i == 0)
//                 strcpy(cPitch, token);
//             else if (i == 1)
//                 strcpy(cYaw, token);
//         }
//         token = strtok(NULL, " ");
//         i++;
//     }
// }
// // #include <wiringPi.h>