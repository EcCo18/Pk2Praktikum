#include <iostream>
#include "LinkedListObject.h"

LinkedListObject::~LinkedListObject()
{
    std::cout << "object deleted!" << std::endl;
}

LinkedListObject::LinkedListObject(char *text)
{
    this->text = text;
}