//
// Created by anna on 03/09/19.
//

#include "Obiettivo.h"

Obiettivo::Obiettivo() {}

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
