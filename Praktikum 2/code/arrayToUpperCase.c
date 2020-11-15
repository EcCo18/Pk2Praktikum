#include "toUpperCase.h"
#include <string.h>
#include <stdio.h>

void array_to_upper_case(char text[])
{
    for(int i=0; i<strlen(text); i++)
    {
        text[i] = to_upper_case(text[i]);
    }
}