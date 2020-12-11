#include "Medium.h"

class Bild : public Medium 
{
    private:
        std::string ort;

    public:
        Bild(std::string titel, int jahr, std::string ort) : Medium(titel, jahr), ort(ort){}

        inline std::string getOrt()
        {
            return ort;
        }

        void setOrt(std::string ort);
        
        void druckeDaten();
};