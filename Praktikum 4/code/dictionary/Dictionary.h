#include "DictionaryField.h"

class Dictionary
{
private:
    int len;
    int counter;
    DictionaryField array[100];
public:
    Dictionary(const int len);
    int insertMemeber(const int *number);
    int deleteMember(const int *number);
    int isMember(const int *number);
};