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

LinkedList::LinkedList(const LinkedList &cpyList)
{
    std::cerr << "copy const called!" << std::endl;

    this->counter = 0;
    this->first = NULL;
    this->last = NULL;

    if(cpyList.counter > 0)
    {
        LinkedListObject *tmp = cpyList.first;

        for(int i=0; i<cpyList.counter; i++)
        {
            this->append(new LinkedListObject(tmp->getText()));
            tmp = tmp->getNext();
        }
    }
    
}

//destructor
LinkedList::~LinkedList()
{
    LinkedListObject *object = this->first;

    for(int i=0; i<counter; i++)
    {
        LinkedListObject *next = object->getNext();
        delete object;
        object = next;
    }

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
    return 0; 
}

int LinkedList::insert(LinkedListObject *object, int position)
{
    if(position < counter)
    {
        LinkedListObject *objectsNext = goToPosition(position);
        LinkedListObject *objectsPrevious = goToPosition((position-1));

        object->setNext(objectsNext);
        object->setPrevious(objectsPrevious);

        if(counter == 0) //only object in list
        {
            this->last = object;
            this->last = object;

        }else if(position == 0) //insert at begin
        {
            this->first = object;
            object->setNext(objectsNext);
            object->setPrevious(objectsPrevious);
            objectsNext->setPrevious(object);

        }else //insert in middle
        {
            objectsPrevious->setNext(object);
            objectsNext->setPrevious(object);
            object->setPrevious(objectsPrevious);
            object->setNext(objectsNext);
        }
        
        counter++;
        return 0;

    }else //append at end, the index is bigger than the list
    {
        append(object);
        return 0;
    }
    
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

int LinkedList::index_of(LinkedListObject *objectToSearch)
{
    if(counter > 0)
    {
        LinkedListObject *object = this->first;

        for(int i=0; i<counter; i++)
        {
            if(objectToSearch == object)
            {
                return i;
            }
            object = object->getNext();
        }
    }
    return -1;
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
    if(position >= 0 && position < counter)
    {
        LinkedListObject *object = this->first;

        for(int i=0; i<position; i++)
        {
            object = object->getNext();
        }
        return object;
    }
    return NULL;
}