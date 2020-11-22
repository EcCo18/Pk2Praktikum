#include <stdio.h>
#include "dictonary.h"
#define TRUE 1
#define FALSE 0

int main(void)
{
    int input;
    while(TRUE)
    {
        scanf("%i", &input);
        printf("Input: %i \n", input);
        if(input == -1)
        {
            break;
        }
        int success = insert(input);

        if(success == TRUE)
        {
            puts("Erfolgreich eingefügt \n");
        }else
        {
            puts("Fehler beim Einfügen \n");
        } 
    }

    insert(5);
    insert(5);
    delete(5);
    insert(4);
    int member5 = member(5);

    printf("Ist 5 member? %i", member5);
    return 0;
}