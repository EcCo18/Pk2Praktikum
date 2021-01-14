#include <iostream>
#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedListObject/LinkedListObject.h"
#include "LinkedList/LinkedListIterator/Iterator.h"

void printObject(LinkedListObject *object);

int main(void)
{
    LinkedList linkedList;
    LinkedListObject *object = new LinkedListObject("test123");
    LinkedListObject *object2 = new LinkedListObject("andererTest");
    LinkedListObject *object3 = new LinkedListObject("das dritte object");

    linkedList.append(object);
    linkedList.append(object2);
    linkedList.append(object3);

    linkedList.visit_all(*printObject);

    LinkedList linkedList2 = linkedList;

    linkedList2.visit_all(*printObject);

    Iterator *iteratorList = linkedList2.getIterator();

    while(iteratorList->hasNext())
    {
        printf("iterator Next: %s \n", iteratorList->next()->getText());
    }
}

void printObject(LinkedListObject *object)
{
    std::cout << object->getText() << std::endl;
}