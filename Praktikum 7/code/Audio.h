#include "Medium.h"

class Audio : public Medium 
{
    private:
        std::string interpret;
        int dauer;

    public:
        Audio(std::string titel, int jahr, std::string interpret, int dauer) : Medium(titel, jahr), interpret(interpret), dauer(dauer){}
        
        inline int getDauer()
        {
            return dauer;
        }
        inline std::string getInterpret()
        {
            return interpret;
        }
        
        void setDauer(int dauer);
        void setInterpret(std::string interpret);

        void druckeDaten();
};