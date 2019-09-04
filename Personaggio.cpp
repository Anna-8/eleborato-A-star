//
// Created by anna on 03/09/19.
//

#include "Personaggio.h"


void Personaggio::setX(int x) {
    Personaggio::x = x;
}

int Personaggio::getY() const {
    return y;
}

void Personaggio::setY(int y) {
    Personaggio::y = y;
}

int Personaggio::getX() const {
    return x;
}


void Personaggio::DisegnaPersonaggio(RenderWindow &window) {
    window.draw(sprite);


}

void Personaggio::setPos(int x, int y) {
    if(index!=pos.size())
        Personaggio::sprite.setPosition(pos[index++]);

}


void Personaggio::setPos() {
    if(index!=pos.size())
        Personaggio::sprite.setPosition(pos[index++]);
}

Personaggio::Personaggio() {

}
