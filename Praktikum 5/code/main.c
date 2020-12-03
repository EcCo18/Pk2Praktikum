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
    printf("%s \n", stringcat(str1, str2));

    int number = 49;
    printf("fak 49: %f \n", (double)fak(number));

    int number2 = 49;
    int number3 = 6;
    printf("binom 49,6: %f", (double)binom(number2, number3));
}