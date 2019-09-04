//
// Created by anna on 03/09/19.
//

#ifndef ELABORATO_A_STAR_PERSONAGGIO_H
#define ELABORATO_A_STAR_PERSONAGGIO_H

#include <SFML/Graphics.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Personaggio {
public:
    Personaggio();
    void setX(int x);
    int getX() const;

    int getY() const;
    void setY(int y);

    void setPos(int x, int y);
    void setPos();

    void DisegnaPersonaggio(RenderWindow &window);

private:
    int x;
    int y;
    vector<Vector2f> pos;

    Sprite sprite;
    Texture texture;

    int index=0;




};


#endif //ELABORATO_A_STAR_PERSONAGGIO_H
