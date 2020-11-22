#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct
{
    int deleted;
    int notFree;
    int value;
}field;

//functions
int find_next_position(int index);
int hash_function(int number);

//vars
int counter = 0;
const int len = 2;
field hashMap[len];

int insert(int number)
{
    const int index = hash_function(number);
    if(counter >= len)
    {
        puts("map is full \n");
        return 0;
    }
    else if(hashMap[index].notFree == TRUE)
    {
        int new_index = find_next_position(index);
        printf("Neue Position nach finding: %i für Zahl: %i \n", new_index, number);
        if(new_index == -1)
        {
            return 0;
        }else
        {
            hashMap[new_index].value = number;
            hashMap[new_index].notFree = TRUE;
            hashMap[new_index].deleted = FALSE;
            counter++;
            return 1;
        }
    }else
    {
        printf("Neue Position: %i für Zahl: %i \n", index, number);
        hashMap[index].notFree = TRUE;
        hashMap[index].value = number;
        hashMap[index].deleted = FALSE;
        counter++;
        return 1;
    }
}

void delete(int number)
{
    const int index = hash_function(number);

    int offset = 1;
    int loopCounter = 1;
    int new_index = index;
    while(loopCounter <= 5000)
    {
        if(hashMap[new_index].notFree == TRUE && hashMap[new_index].value == number)
        {
            hashMap[new_index].deleted = TRUE;
            hashMap[new_index].notFree = FALSE;
            counter--;
            printf("%i gefunden und gelöscht an new_index: %i \n", hashMap[new_index].value, new_index);
            break;
        }else if (hashMap[new_index].deleted == TRUE || hashMap[new_index].notFree == TRUE)
        {
            offset *= loopCounter;
            printf(" offset fuer naechsten Loeschversuch: %i \n", offset);
        }else
        {
            break;
        }
        new_index = (index + offset) % len;
        printf(" Neuer Index zum loeschen: %i \n", new_index);
        loopCounter++;
    }
}

int member(const int number)
{
    int const index = hash_function(number);

    int loopCounter = 1;
    int offset = 1;
    int new_index = index;
    while(loopCounter <= 5000)
    {
        if(hashMap[new_index].notFree == TRUE && hashMap[new_index].value == number)
        {
            printf("Zahl gefunden an new_index: %i \n", new_index);
            break;
        }else if(hashMap[new_index].deleted == TRUE || hashMap[new_index].notFree == TRUE)
        {
            offset *= loopCounter;
        }else
        {
            return FALSE;
        }
        new_index = (index + offset) % len;
        printf(" index fuer naechste Suche: %i \n", new_index);
        loopCounter++;
    }
    return TRUE;
}

int hash_function(const int number)
{
    return (number % len);
}

int find_next_position(int index)
{
    int number = 1;
    int new_index;

    int i = 1;
    int loopCounter = 1;
    while(number != 0 && loopCounter <= 5000)
    {
        i = (i * loopCounter);
        if(hashMap[(index + i) % len].notFree == FALSE)
        {
            return (index + i) % len;
        }
        loopCounter++;
    }
    return -1;
}