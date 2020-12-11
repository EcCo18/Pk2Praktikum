#include <iostream>
#include <string>

#ifndef MEDIUM_H
#define MEDIUM_H

class Medium
{
    private:
        static int id;
        const int objId;
        std::string titel;
        int jahr;

    public:
        int alter();
        virtual void druckeDaten();

        inline int getObjId()
        {
            return objId;
        }
        inline std::string getTitle()
        {
            return titel;
        }
        inline int getJahr()
        {
            return jahr;
        }

        void setJahr(int jahr);
        void setTitle(std::string);

        Medium(std::string titel, int jahr);
        ~Medium();
};   
#endif