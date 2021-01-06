#include <iostream>
#include "LinkedList.h"
#include "LinkedListObject/LinkedListObject.h"

//constructor
LinkedList::LinkedList()
{
    this->counter = 0;
}

//destructor
LinkedList::~LinkedList()
{
    std::cout << "LinkedList deleted!" << std::endl;
}

//functions
int LinkedList::append(LinkedListObject *object)
{
    //first and only element
    if(this->counter == 0)
    {
        object->setNext(NULL);
        object->setPrevious(NULL);

        this->first = object;
        this->last = object;
    }else //append at the end
    {
        object->setPrevious(this->last);
        object->setNext(NULL);

        this->last->setNext(object);
        this->last = object;
    }  

    this->counter++; 
}

int LinkedList::insert(LinkedListObject *object, int position)
{

}

int LinkedList::remove(int position)
{

}

LinkedListObject* LinkedList::get(int position)
{
    if(position > counter)
    {
        return NULL;
    }else
    {
        LinkedListObject *object = this->first;

        for(int i=0; i<position; i++)
        {
            object = object->getNext();
        }
        return object;
    }
}

int LinkedList::index_of(LinkedListObject *object)
{

}

void LinkedList::visit_all(void (*work)(LinkedListObject *t))
{

}