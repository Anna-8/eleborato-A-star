//
// Created by anna on 08/07/19.
//

#include "Mappa.h"
#include <iostream>
#include "Punto.h"


Mappa::Mappa(int DimMappa) {
    this->DimMappa = DimMappa;
    switch (DimMappa) {
        case 1:
            rows = 30;
            columns = 40;
        case 2:
            rows = 20;
            columns = 35;
        case 3:
            rows = 25;
            columns = 25;
    }
    matrice = new int[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrice[i * columns + j] = rand() % 10;//genera numeri tra 0 e 9

        }
    }
    std::cout << " la matrice è " << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            std::cout << matrice[i * columns + j] << " ";
        }
        std::cout << std::endl;
    }

}

int Mappa::GetMap(Punto p) {
    if( p.getX() < 0 || p.getX() >= rows || p.getY() < 0 ||p.getY() >= columns)
        return 9;

    return matrice[(p.getX())*columns+ (p.getY())];
}
