#include <iostream>
#include "dictionary/Dictionary.h"

void test();

int main(void)
{
    test();
}

void test()
{
    Dictionary dictionary(100);
    printf("Counter: %i\n", dictionary.getCounter());
    printf("%i\n", dictionary.insertMemeber(152));
    printf("Counter: %i\n", dictionary.getCounter());
    printf("is 152 member?: %i\n", dictionary.isMember(152));
    printf("is 122 member?: %i\n", dictionary.isMember(122));
}