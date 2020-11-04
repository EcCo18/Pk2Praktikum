#include <stdio.h>
#include <math.h>

void printIntToBin(int x)
{
    int tmp = 0;

    for(int i=15; i>= 0; i--)
    {
        if((tmp = pow(2, i)) <= x)
        {
            printf("1");
            x = (x - tmp);

        }else
        {
            printf("0");
        }
    }
}