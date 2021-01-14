#include "../LinkedListObject/LinkedListObject.h"

#ifndef ITERATOR_H
#define ITERATOR_H

class Iterator
{
    private:
        LinkedListObject *object;

    public:
        LinkedListObject* next();
        bool hasNext();

        //inline
        inline void setFirst(LinkedListObject *first)
        {
            this->object = first;
        }

        Iterator(LinkedListObject *first);
        ~Iterator();
};

#endif