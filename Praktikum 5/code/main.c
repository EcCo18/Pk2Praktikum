#include <stdio.h>
#include "functions.h"

#define true 1
#define false 0

int main(void)
{
    char s[] = "test test test ";
    printf("Count space: %i\n", countspace(s));

    double n[] = {1, -5, 8, -5.1};
    printf("Min: %f \n", min(n, 4));

    char *str1 = "test";
    char *str2 = " lol";
    printf("%s", stringcat(str1, str2));
}