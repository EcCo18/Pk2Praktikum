#include <iostream>
#include "LinkedListObject/LinkedListObject.h"
#include "LinkedListIterator/Iterator.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList
{
    private:
        LinkedListObject *first;
        LinkedListObject *last;
        int counter;

        LinkedListObject *goToPosition(int position);

    public:
        int append(LinkedListObject *object);
        int insert(LinkedListObject *object, int position);
        int remove(int position);
        LinkedListObject *get(int position);
        int index_of(LinkedListObject *objectToSearch);

        void visit_all(void (*work)(LinkedListObject *t));

        //inline
        inline LinkedListObject *getFirst()
        {
            return first;
        }
        inline LinkedListObject *getLast()
        {
            return last;
        }
        inline int getCounter()
        {
            return counter;
        }
        inline Iterator *getIterator()
        {
            return new Iterator(this->first);
        }

        LinkedList();
        LinkedList(const LinkedList &cpyList);
        ~LinkedList();
};

#endif