#include <iostream>
#include "LinkedList/LinkedList.h"
#include "LinkedList/LinkedListObject/LinkedListObject.h"

int main(void)
{
    LinkedList *linkedList = new LinkedList();
    LinkedListObject *object = new LinkedListObject("test123");
    LinkedListObject *object2 = new LinkedListObject("andererTest");

    linkedList->append(object);
    linkedList->append(object2);

    printf("Erstes Element: %s \n", linkedList->get(1)->getText());

    delete linkedList;
}