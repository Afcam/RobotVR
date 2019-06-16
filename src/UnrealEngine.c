#include "UnrealEngine.h"

Axes *UEAxes(char *msg)
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

Rear *UERear(char *msg)
{
    Rear *Control = (Rear*)malloc(sizeof(Rear));
    int Val = atoi(msg);

    if (Val <= 0)
    {
        Control->Dir = 'B';
        Control->Speed = abs(Val);
    }
    else
    {
        Control->Dir = 'F';
        Control->Speed = abs(Val);
    }

    return Control;
}