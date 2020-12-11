#include "Bild.h"

void Bild::setOrt(std::string ort)
{
    this->ort = ort;
}

void Bild::druckeDaten()
{
    printf("ID=%i \"%s\" aufgenommen im Jahr %i in %s \n", this->getObjId(), this->getTitle().c_str(), this->getJahr(), 
    this->getOrt().c_str());
}