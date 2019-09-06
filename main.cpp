#include <iostream>
#include <stdio.h>
#include <math.h>
#include "Mappa.h"
#include "Schermo.h"
#include <SFML/Graphics.hpp>
#include "Personaggio.h"



int main() {

    srand((unsigned int)time(NULL));
    Personaggio p=Personaggio::crea();
    Obiettivo o;
    Schermo schermo( o);
    schermo.generaSchermo( o);

    return 0;


}