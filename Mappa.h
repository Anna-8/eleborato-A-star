//
// Created by anna on 08/07/19.
//

#ifndef ELEBORATO_A_STAR_MAPPA_H
#define ELEBORATO_A_STAR_MAPPA_H

#include <stdlib.h>
#include "Punto.h"


class Mappa {
private:
    int * matrice;
    int rows;
    int columns;
    int DimMappa;


public:
    Mappa(int DimMappa);
    int GetMap(Punto P);

};

#endif //ELEBORATO_A_STAR_MAPPA_H
