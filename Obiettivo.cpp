//
// Created by anna on 03/09/19.
//

#include "Obiettivo.h"
#include "Mappa.h"
#define TILE 32

Obiettivo::Obiettivo() {
    int xf;
    int yf;
    do {
        xf = static_cast<int>(random() % Mappa::crea().getColumns());
        yf = static_cast<int>(random() % Mappa::crea().getRows());
    }while (Mappa::crea().getTiles(xf,yf) >= 9);
    this->x=xf;
    this->y= yf;
    texture.loadFromFile("nido.png");
    sprite.setTexture(texture);
    sprite.scale(0.15,0.15);
    sprite.setPosition(y*TILE,x*TILE);
}

Obiettivo::~Obiettivo() {

}

int Obiettivo::getX() const {
    return x;
}

void Obiettivo::setX(int x) {
    Obiettivo::x = x;
}

int Obiettivo::getY() const {
    return y;
}

void Obiettivo::setY(int y) {
    Obiettivo::y = y;
}

void Obiettivo::setpos(int x, int y) {
    Obiettivo::sprite.setPosition(x,y);

}

void Obiettivo::drawPersonaggio(RenderWindow &window) {
    window.draw(sprite);

}
