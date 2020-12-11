#include "Audio.h"

void Audio::druckeDaten()
{
    printf("ID=%i \"%s\" von %s aus %i Spieldauer: %i sek. \n", this->getObjId(), this->getTitle().c_str(),
     this->getInterpret().c_str(), this->getJahr(), this->getDauer());
}

void Audio::setDauer(int dauer)
{
    this->dauer = dauer;
}

void Audio::setInterpret(std::string interpret)
{
    this->interpret = interpret;
}