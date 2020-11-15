#include <stdio.h>
#include "toUpperCase.h"

int main(void)
{
    char c = 'c';
    
    char erg = to_upper_case(c);
    printf("%c", erg);
}