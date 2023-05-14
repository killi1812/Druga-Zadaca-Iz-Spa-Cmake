//
// Created by fran on 07.05.23..
//

#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include "Dot.h"
#include <array>

#define sizeY 108
#define sizeX 192

class Grid {
    std::array<Dot, sizeY * sizeX> *dots = new std::array<Dot, sizeY * sizeX>;
    std::array<Dot, sizeY * sizeX> *old = new std::array<Dot, sizeY * sizeX>;
    int spawn_rate;
    double speed;
    sf::RenderWindow *window;
    sf::Clock clock;

    int susjedi(std::array<Dot, 108 * 192> *dot, int i);

    void next_gen();

public:
    ~Grid();

    Grid(sf::RenderWindow *window, double speed, int spawn_rate);

    void draw();
};


#endif //GAMEOFLIFE_GRID_H
