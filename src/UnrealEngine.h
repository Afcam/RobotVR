#include <stdio.h>

#include <string.h>
#include <stdlib.h>

typedef struct
{
    float Pich;
    float Yaw;
    float Roll;
} Axes;



Axes *UDP_30000(char *msg);