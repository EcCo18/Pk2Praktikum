#include <iostream>
#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedListObject/LinkedListObject.h"

int main(void)
{
    LinkedList *linkedList = new LinkedList();
    LinkedListObject *object = new LinkedListObject("test123");
    LinkedListObject *object2 = new LinkedListObject("andererTest");
    LinkedListObject *object3 = new LinkedListObject("das dritte object");

    linkedList->append(object);
    linkedList->append(object2);
    linkedList->append(object3);

    

    delete linkedList;
}