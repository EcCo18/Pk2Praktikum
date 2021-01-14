#include <iostream>
#include "Iterator.h"

Iterator::Iterator(LinkedListObject *first)
{
    this->object = first;
}

Iterator::~Iterator()
{

}

//functions
bool Iterator::hasNext()
{
    if(this->object != NULL)
        return true;

    return false;
}

LinkedListObject* Iterator::next()
{
    if(object != NULL)
    {
        LinkedListObject *tmp = object;
        object = object->getNext();

        return tmp;
    }
    return NULL;
}