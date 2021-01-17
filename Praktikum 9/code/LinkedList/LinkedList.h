#include <iostream>
#include "LinkedListObject/LinkedListObject.h"
#include "LinkedListIterator/Iterator.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
    private:
        LinkedListObject<T> *first;
        LinkedListObject<T> *last;
        int counter;

        LinkedListObject<T> *goToPosition(int position);

    public:
        int append(T *object);
        int insert(T *object, int position);
        int remove(int position);
        LinkedListObject<T> *get(int position);
        int index_of(T *objectToSearch);

        void visit_all(void (*work)(LinkedListObject<T> *t));

        //inline
        inline LinkedListObject<T> *getFirst()
        {
            return first;
        }
        inline LinkedListObject<T> *getLast()
        {
            return last;
        }
        inline int getCounter()
        {
            return counter;
        }
        inline Iterator<T> *getIterator()
        {
            return new Iterator<T>(this->first);
        }

        LinkedList();
        LinkedList(const LinkedList &cpyList);
        ~LinkedList();
};

//constructor
template <class T>
LinkedList<T>::LinkedList()
{
    this->counter = 0;
    this->first = NULL;
    this->last = NULL;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList &cpyList)
{
    std::cerr << "copy const called!" << std::endl;

    this->counter = 0;
    this->first = NULL;
    this->last = NULL;

    if(cpyList.counter > 0)
    {
        LinkedListObject<T> *tmp = cpyList.first;

        for(int i=0; i<cpyList.counter; i++)
        {
            this->append(new LinkedListObject<T>(tmp->getText()));
            tmp = tmp->getNext();
        }
    }
}

//destructor
template <class T>
LinkedList<T>::~LinkedList()
{
    LinkedListObject<T> *object = this->first;

    for(int i=0; i<counter; i++)
    {
        LinkedListObject<T> *next = object->getNext();
        delete object;
        object = next;
    }

    std::cout << "LinkedList deleted!" << std::endl;
}

//functions
template <class T>
int LinkedList<T>::append(T *object)
{
    LinkedListObject<T> *linkedListObject = new LinkedListObject<T>(object);
    //first and only element
    if(this->counter == 0)
    {
        linkedListObject->setNext(NULL);
        linkedListObject->setPrevious(NULL);

        this->first = linkedListObject;
        this->last = linkedListObject;

    }else //append at the end
    {
        linkedListObject->setPrevious(this->last);
        linkedListObject->setNext(NULL);

        this->last->setNext(linkedListObject);
        this->last = linkedListObject;
    }  

    this->counter++;
    return 0; 
}

template <class T>
int LinkedList<T>::insert(T *object, int position)
{
    LinkedListObject<T> *linkedListObject = new LinkedListObject<T>(object);

    if(position < counter)
    {
        LinkedListObject<T> *objectsNext = goToPosition(position);
        LinkedListObject<T> *objectsPrevious = goToPosition((position-1));

        linkedListObject->setNext(objectsNext);
        linkedListObject->setPrevious(objectsPrevious);

        if(counter == 0) //only object in list
        {
            this->first = linkedListObject;
            this->last = linkedListObject;

        }else if(position == 0) //insert at begin
        {
            this->first = linkedListObject;

            linkedListObject->setNext(objectsNext);
            linkedListObject->setPrevious(objectsPrevious);
            objectsNext->setPrevious(linkedListObject);

        }else //insert in middle
        {
            objectsPrevious->setNext(linkedListObject);
            objectsNext->setPrevious(linkedListObject);
            linkedListObject->setPrevious(objectsPrevious);
            linkedListObject->setNext(objectsNext);
        }
        
        counter++;
        return 0;

    }else //append at end, the index is bigger than the list
    {
        append(object);
        return 0;
    }
    
}

template <class T>
int LinkedList<T>::remove(int position)
{
    if(position < this->counter)
    {
        LinkedListObject<T> *object = goToPosition(position);

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

template <class T>
LinkedListObject<T>* LinkedList<T>::get(int position)
{
    if(position > counter)
    {
        return NULL;
    }else
    {
        return goToPosition(position);
    }
}

template <class T>
int LinkedList<T>::index_of(T *objectToSearch)
{
    if(counter > 0)
    {
        LinkedListObject<T> *object = this->first;

        for(int i=0; i<counter; i++)
        {
            if(objectToSearch == object->getObject())
            {
                return i;
            }
            object = object->getNext();
        }
    }
    return -1;
}

template <class T>
void LinkedList<T>::visit_all(void (*work)(LinkedListObject<T> *t))
{
    Iterator<T> *iterator = getIterator();

    while(iterator->hasNext())
    {
        work(iterator->next());
    }
}

//private functions
template <class T>
LinkedListObject<T> *LinkedList<T>::goToPosition(int position)
{
    if(position >= 0 && position < counter)
    {
        LinkedListObject<T> *object = this->first;

        for(int i=0; i<position; i++)
        {
            object = object->getNext();
        }
        return object;
    }
    return NULL;
}

#endif