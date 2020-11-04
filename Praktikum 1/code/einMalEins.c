#include <stdio.h>

void printEinMalEins()
{
    int from;
    puts("Kleinste Zahl Ein mal Eins eigeben.\n");
    scanf("%d", &from);

    int to;
    puts("Groesste Zhal Ein mal Eins eigeben.\n");
    scanf("%d", &to);


    for(int i = 1; i <= 10; i++)
    {
        for(int p = from; p <= to; p++)
        {
            printf("%d ", (p*i));
        }
        puts("\n");
    }
}