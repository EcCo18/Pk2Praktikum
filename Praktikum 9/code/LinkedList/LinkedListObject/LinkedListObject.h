

#ifndef LINKEDLISTOBJECT_H
#define LINKEDLISTOBJECT_H

template <class T>
class LinkedListObject
{
    private:
        LinkedListObject *previous;
        LinkedListObject *next;
        T *object;

    public:    
        //inline
        inline T *getObject()
        {
            return object;
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

        LinkedListObject(T *object);
        ~LinkedListObject();
};

template <class T>
LinkedListObject<T>::~LinkedListObject()
{
    std::cout << "object deleted!" << std::endl;
}

template <class T>
LinkedListObject<T>::LinkedListObject(T *object)
{
    this->object = object;
}

#endif