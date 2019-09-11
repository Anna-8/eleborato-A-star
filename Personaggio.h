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
    Personaggio(int x, int y);
    int getX() const;

    int getY() const;

    void setPos(int x, int y);
    void setPos();

    int getIndex() const;


    const vector<Vector2f> &getCoordinate() const;

    void DisegnaPersonaggio(RenderWindow &window);
    static Personaggio& crea();
    static Personaggio& crea(int x, int y);


    void setCoordinate(int x, int y);

private:
    int x;
    int y;

    vector<Vector2f> coordinate;

    Sprite sprite;
    Texture texture;

    int index=0;




};


#endif //ELABORATO_A_STAR_PERSONAGGIO_H
