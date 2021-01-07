#include <iostream>
#include "LinkedList.h"
#include "LinkedListObject/LinkedListObject.h"

//constructor
LinkedList::LinkedList()
{
    this->counter = 0;
    this->first = NULL;
    this->last = NULL;
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
    if(position < this->counter)
    {
        LinkedListObject *object = goToPosition(position);

        if(object->getPrevious() != NULL && object->getNext() != NULL) //removed is in middle of two
        {
            object->getPrevious()->setNext(object->getNext());
            object->getNext()->setPrevious(object->getPrevious());

        }else if(object->getPrevious() != NULL && object->getNext() == NULL) //remove on last
        {
            object->getPrevious()->setNext(NULL);
            this->last = object->getPrevious();

        }else if(object->getPrevious() == NULL && object->getNext() != NULL) //remove on first
        {
            object->getNext()->setPrevious(NULL);
            this->first = object->getNext();

        }else //is only element in list
        {
            this->first = NULL;
            this->last = NULL;
        }

        delete object; //delete removed object
        this->counter--;
        return 0;
    }
    else
    {
        return -1;
    } 
}

LinkedListObject* LinkedList::get(int position)
{
    if(position > counter)
    {
        return NULL;
    }else
    {
        return goToPosition(position);
    }
}

int LinkedList::index_of(LinkedListObject *object)
{

}

void LinkedList::visit_all(void (*work)(LinkedListObject *t))
{
    if(counter > 0)
    {
        int i=0;
        LinkedListObject *object = this->first;

        do
        {
            work(object);
            object = object->getNext();
            i++;
        } while (i < counter);
        
    }
}

//private functions
LinkedListObject *LinkedList::goToPosition(int position)
{
    LinkedListObject *object = this->first;

        for(int i=0; i<position; i++)
        {
            object = object->getNext();
        }
        return object;
}