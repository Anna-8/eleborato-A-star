//
// Created by anna on 03/09/19.
//

#ifndef ELABORATO_A_STAR_OBIETTIVO_H
#define ELABORATO_A_STAR_OBIETTIVO_H
#include <SFML/Graphics.hpp>
using namespace sf;



class Obiettivo {
public:
    Obiettivo();
    Obiettivo(int x,int y);
    virtual ~Obiettivo();
    void drawPersonaggio(RenderWindow &window);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    void setpos(int x, int y);

private:
    Sprite sprite;
    Texture texture;
    int x;
    int y;

};


#endif //ELABORATO_A_STAR_OBIETTIVO_H
