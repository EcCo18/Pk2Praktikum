class DictionaryField
{
    private:
        int value;
        bool hasNextBoolean;
        DictionaryField *next;
    public:
        DictionaryField();
        DictionaryField(const int value);
        void setNextBoolean(const bool hasNext);
        bool hasNext();
        int getValue();
        void setNext(DictionaryField *next);
        DictionaryField* getNext();
        void printData();
};