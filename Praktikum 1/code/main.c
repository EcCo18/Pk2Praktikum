#include "../code/asciiCode.h"
#include "../code/einMalEins.h"
#include "../code/intToBin.h"
#include <stdio.h>

int main(void)
{
    printAsciiTable(10);
    puts("\n");
    printEinMalEins();
    puts("\n");
    printIntToBin(1234);
}