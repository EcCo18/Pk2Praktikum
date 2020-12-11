#include "Audio.h"
#include "Bild.h"

int main(void)
{
    Audio *audio1 = new Audio("TestAudio", 1922, "ACDC", 200);
    audio1->druckeDaten();
    Bild *bild1 = new Bild("TestBild", 1980, "Dortmund");
    bild1->druckeDaten();
}