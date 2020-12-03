#include <iostream>
#include "Dictionary.h"

Dictionary::Dictionary(const int len)
{
    this->len = 100;
    this->counter = 0;
}

int Dictionary::insertMemeber(int number)
{
    if(counter < len)
    {
        const int index = generateHash(number);
        printf("Index zum einfuegen: %i\n", index);

        DictionaryField dictionaryField(number);
        dictionaryField.setNextBoolean(false);

        if(this->lastElements[index] != nullptr)
        {
            lastElements[index]->setNext(&dictionaryField);
            lastElements[index]->setNextBoolean(true);
            lastElements[index] = &dictionaryField;
            this->counter++;
            return 1;
        }else
        {
            this->lastElements[index] = &dictionaryField;
            this->array[index] = dictionaryField;
            this->counter++;
            return 1;
        }
    }else
    {
        return 0;
    } 
}

int Dictionary::deleteMember(int number)
{
    if(!isMember(number))
    {
        return 0;
    }else
    {
        const int index = generateHash(number);
        DictionaryField field = array[index];
        DictionaryField *previousField = nullptr;
        do
        {
            if(field.getValue() == number)
            {
                if(field.hasNext())
                {
                    if(previousField != nullptr) //is not first member
                    {
                        previousField->setNext(field.getNext());
                    }else //is first member
                    {
                        //array[index] = field.getNext();
                    }
                    
                }else //is last
                {
                   if(previousField != nullptr) //has member before
                   {
                       previousField->setNextBoolean(false);
                       previousField->setNext(nullptr);
                   }else //is last and first
                   {
                       this->lastElements[index] = nullptr;
                       array[index] = NULL;
                   }
                   
                }
                
            }
            previousField = &field;
            //field = field->getNext(); <--important!
        } while (field.hasNext());
        return -1;
    }
}

int Dictionary::isMember(int number)
{
    const int index = generateHash(number);

    if(this->lastElements[index] == nullptr)
    {
        return 0;
    }else
    {
        DictionaryField *field = &array[index];
        do
        {
            printf("%i\n", field->getValue());
            if(field->getValue() == number)
            {
                return 1;
            }
            field = field->getNext();
        } while (field->hasNext());
        return 0;
    }
}

int Dictionary::getCounter()
{
    return this->counter;
}

int Dictionary::generateHash(int number)
{
    return (number % len);
}
