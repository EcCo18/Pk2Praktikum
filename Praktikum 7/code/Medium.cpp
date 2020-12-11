#include "Medium.h"

int Medium::id = 0;

void Medium::setJahr(int jahr)
{
    this->jahr = jahr;
}

void Medium::setTitle(std::string titel)
{
    this->titel = titel;
}

Medium::~Medium()
{
    this->id--;
}

Medium::Medium(std::string titel, int jahr) : objId(id)
{
    this->titel = titel;
    this->jahr = jahr;
    id++;
}

void Medium::druckeDaten(){}

int Medium::alter()
{
    return 2020 - this->jahr;
}