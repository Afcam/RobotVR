#include "UnrealEngine.h"

Axes *UDP_30000(char *msg)
{
    Axes *Rot = malloc(sizeof(Axes));
    char *token;
    int i = 0;

    token = strtok(msg, " ");
    for (i = 0; token != NULL; i++)
    {
        switch (i)
        {
        case (0):
            // strcpy(Rot->Pich, token);
            Rot->Pich = atof(token + 2 );
            break;
        case (1):
            // strcpy(Rot->Yaw, token);
            Rot->Yaw = atof(token + 2);
            break;
        default:
            // strcpy(Rot->Roll, token);
            Rot->Roll = atof(token + 2);
            break;
        }
        token = strtok(NULL, " ");
    }
    return Rot;
}