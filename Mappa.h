//
// Created by anna on 08/07/19.
//

#ifndef ELEBORATO_A_STAR_MAPPA_H
#define ELEBORATO_A_STAR_MAPPA_H


#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Mappa {
private:
    Texture tex;
    VertexArray m_vertices;
    sf::RenderStates states;
    enum Mappe : char{mappa1 = 'a',mappa2 = 'b' ,mappa3 = 'c'};
    int rows=0;
    int columns=0;
    vector<vector<int>>tiles;
    Mappa(int dim);
    Mappa(char x);
    int* lvlmap;
    vector<int>type;



public:
    static Mappa&crea(int dim =rand()%3 );
    static Mappa&crea(char x);


    int getColumns() const;
    int getRows() const ;
    int GetMap(int x, int y);
    void findDimension();
    bool load();
    void DisegnaMappa(RenderWindow &window);

    int getTiles(int x, int y) const;


};

#endif //ELEBORATO_A_STAR_MAPPA_H
