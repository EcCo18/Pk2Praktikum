#include "DictionaryField.h"

class Dictionary
{
private:
    int len;
    int counter;
    DictionaryField array[100];
    DictionaryField *lastElements[100] = {};
    int generateHash(int number);
public:
    Dictionary(const int len);
    int insertMemeber(int number);
    int deleteMember(int number);
    int isMember(int number);
    int getCounter();
};