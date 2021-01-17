#include <iostream>
#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedListObject/LinkedListObject.h"
#include "LinkedList/LinkedListIterator/Iterator.h"

void printAllObjects(LinkedListObject<int> *object);

int main(void)
{
    LinkedList<int> *linkedList = new LinkedList<int>();

    int *newInt = new int();

    linkedList->append(new int(123));
    linkedList->append(new int(123455));
    linkedList->append(new int(25656));

    linkedList->visit_all(*printAllObjects);

    delete linkedList;
}

void printAllObjects(LinkedListObject<int> *object)
{
    printf("%i\n", *object->getObject());
}