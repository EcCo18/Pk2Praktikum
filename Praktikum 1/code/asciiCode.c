#include <stdio.h>

void printAsciiTable(int width)
{
    for(int i = 32; i <= 126; i++)
    {
        if((i-32) % width == 0)
        {
            puts("\n");
        }
        printf("%d %c | ", i, i);
    }
}