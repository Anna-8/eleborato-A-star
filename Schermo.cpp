//
// Created by anna on 29/08/19.
//

#include "Schermo.h"
#include "Mappa.h"
#include "Personaggio.h"
#include "Obiettivo.h"
#include "stlastar.h"
#include "MapSearchNode.h"

#define TILE 32



Schermo::~Schermo() = default;


Schermo::Schermo() {
    Mappa::crea().load();
    view.setSize(Mappa::crea().getRows()*TILE, Mappa::crea().getColumns()*TILE);
    view.setCenter(Mappa::crea().getRows()*TILE/2, Mappa::crea().getColumns()*TILE/2);
    window.create(VideoMode(800,600),"Algoritmo A*");
    window.setFramerateLimit(60); //Limit the framerate to a maximum fixed frequenc,Parameters: Framerate limit, in frames per seconds
    sf::WindowHandle handle = window.getSystemHandle(); //Get the OS-specific handle of the window
    sf::Window window(handle);
}

void Schermo::generaSchermo(Obiettivo obiettivo) {

    while (window.isOpen()) {

        while (window.pollEvent(event)) { //Pop the event on top of the event queue, if any, and return it.

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.setView(view); //Change the current active view

        window.setActive(); //Activate or deactivate the window as the current target for OpenGL rendering.

        window.clear();

        Mappa::crea().DisegnaMappa(window);

        obiettivo.drawPersonaggio(window);

        if (!eseguito)
            Astar(obiettivo);
        this->setEseguito(true);


        times=clock.getElapsedTime(); //returns the time elapsed since the last call to restart()

        if(times.asSeconds()>1){
            Personaggio::crea().setPos();
            clock.restart(); //puts the time counter back to zero
        }

        Personaggio::crea().DisegnaPersonaggio(window);

        window.display(); //rendering has been done for the current frame, in order to show it on screen
    }

}

void Schermo::Astar( Obiettivo obiettivo) {

    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount = 0;

    const unsigned int NumSearches = 1;

    while (SearchCount < NumSearches) {

        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = Personaggio::crea().getX();
        nodeStart.y = Personaggio::crea().getY();
        cout << "Punto di partenza (" << nodeStart.x << "," << nodeStart.y << ")" << endl;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = obiettivo.getX();
        nodeEnd.y = obiettivo.getY();
        cout << "Punto di arrivo (" << nodeEnd.x << "," << nodeEnd.y << ")" << endl;

        // Set Start and goal states

        astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do {
            SearchState = astarsearch.SearchStep();

            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

                int len = 0;

                cout << "Open:\n";
                MapSearchNode *p = astarsearch.GetOpenListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    ((MapSearchNode *)p)->PrintNodeInfo();
#endif
                    p = astarsearch.GetOpenListNext();

                }

                cout << "Open list has " << len << " nodes\n";

                len = 0;

                cout << "Closed:\n";
                p = astarsearch.GetClosedListStart();
                while( p )
                {
                    len++;
#if !DEBUG_LIST_LENGTHS_ONLY
                    p->PrintNodeInfo();
#endif
                    p = astarsearch.GetClosedListNext();
                }

                cout << "Closed list has " << len << " nodes\n";
#endif

        } while (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

        if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED) {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;

            node->PrintNodeInfo();

            for (;;) {
                node = astarsearch.GetSolutionNext();



                if (!node) {
                    break;
                }


                node->PrintNodeInfo();
                steps++;



            };


            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();


        } else if (SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED) {
            cout << "Search terminated. Did not find goal state\n";

        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount++;

        astarsearch.EnsureMemoryFreed();


    }


}

void Schermo::setEseguito(bool eseguito) {
    Schermo::eseguito = eseguito;
}
