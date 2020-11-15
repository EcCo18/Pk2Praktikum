#include <stdio.h>
#include "toUpperCase.h"
#include "arrayToUpperCase.h"
#include "queue.h"

void toUpperCaseTest();
void arrayToUpperCaseTest();
void queueTest();

int main(void)
{
    toUpperCaseTest();
    arrayToUpperCaseTest();
    queueTest();
}

void toUpperCaseTest()
{
    char c = 'c';

    char erg = to_upper_case(c);
    printf("to upper case test: %c \n", erg);
}

void arrayToUpperCaseTest()
{
    char text[] = "dasisteintest";
    array_to_upper_case(text);
    printf("array to upper case test: %s \n", text);
}

void queueTest()
{
    
}