//
// Created by anna on 29/08/19.
//

#ifndef ELABORATO_A_STAR_SCHERMO_H
#define ELABORATO_A_STAR_SCHERMO_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Obiettivo.h"
#include "Personaggio.h"

using namespace sf;

class Schermo {
public:
    Schermo();
    ~Schermo();
    void generaSchermo(Obiettivo obiettivo);
    void Astar( Obiettivo obiettivo);

private:
    View view; //a camera in the 2D scene
    Time times; //encapsulates a time value in a flexible way
    Clock clock;// a lightweight class for measuring time.
    bool eseguito=false;
public:
    void setEseguito(bool eseguito);

private:
    sf::Event event; //holds all the informations about a system event that just happened
    sf::RenderWindow window; //is the main class of the Graphics module



};


#endif //ELABORATO_A_STAR_SCHERMO_H
