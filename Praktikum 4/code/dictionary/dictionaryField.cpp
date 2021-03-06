#include "DictionaryField.h"
#include <iostream>

DictionaryField::DictionaryField()
{
    this->hasNextBoolean = false;
}

DictionaryField::DictionaryField(const int value)
{
    this->value = value;
    this->hasNextBoolean = false;
}

void DictionaryField::setNextBoolean(const bool hasNext)
{
    this->hasNextBoolean = hasNext;
}

int DictionaryField::getValue()
{
    return this->value;
}

void DictionaryField::setNext(DictionaryField *next)
{
    this->next = next;
} 

bool DictionaryField::hasNext()
{
    return this->hasNextBoolean;
}

DictionaryField* DictionaryField::getNext()
{
    return this->next;
}

void DictionaryField::printData()
{
    std::cout << "Value: " << this->value << " ,hasNext: " << this->hasNextBoolean << "\n"; 
}
