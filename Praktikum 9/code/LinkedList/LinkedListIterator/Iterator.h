#include "../LinkedListObject/LinkedListObject.h"

#ifndef ITERATOR_H
#define ITERATOR_H

template <class T>
class Iterator
{
    private:
        LinkedListObject<T> *object;

    public:
        LinkedListObject<T>* next();
        bool hasNext();

        //inline
        inline void setFirst(LinkedListObject<T> *first)
        {
            this->object = first;
        }

        Iterator(LinkedListObject<T> *first);
        ~Iterator();
};

template <class T>
Iterator<T>::Iterator(LinkedListObject<T> *first)
{
    this->object = first;
}

template <class T>
Iterator<T>::~Iterator()
{

}

//functions
template <class T>
bool Iterator<T>::hasNext()
{
    if(this->object != NULL)
        return true;

    return false;
}

template <class T>
LinkedListObject<T>* Iterator<T>::next()
{
    if(object != NULL)
    {
        LinkedListObject<T> *tmp = object;
        object = object->getNext();

        return tmp;
    }
    return NULL;
}

#endif