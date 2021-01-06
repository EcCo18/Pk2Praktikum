

#ifndef LINKEDLISTOBJECT_H
#define LINKEDLISTOBJECT_H

class LinkedListObject
{
    private:
        LinkedListObject *previous;
        LinkedListObject *next;
        char* text;

    public:    
        //inline
        inline char *getText()
        {
            return text;
        }
        inline LinkedListObject *getPrevious()
        {
            return previous;
        }
        inline LinkedListObject *getNext()
        {
            return next;
        }
        inline void setNext(LinkedListObject *nextObject)
        {
            next = nextObject;
        }
        inline void setPrevious(LinkedListObject *previousObject)
        {
            previous = previousObject;
        }

        LinkedListObject(char* text);
        ~LinkedListObject();
};

#endif