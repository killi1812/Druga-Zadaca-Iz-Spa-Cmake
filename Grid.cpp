//
// Created by fran on 07.05.23..
//

#include "Grid.h"
#include <iostream>

void Grid::draw() {
    for (auto d: *dots) {
        d.draw(*window);
    }
    if (clock.getElapsedTime().asMilliseconds() >= speed) {
        next_gen();
        clock.restart();
    }
}

Grid::Grid(sf::RenderWindow *window, double speed, int spawn_rate) {
    this->speed = speed;
    this->spawn_rate = spawn_rate;
    this->window = window;
    int x = 0, y = 0;

    for (auto i = 0; i < dots->size(); ++i) {
        (*dots)[i].move(x * 10, y * 10);
        (*dots)[i].FirstBorn(spawn_rate);
        x++;
        if (x == 192) {
            x = 0;
            y++;
        }
    }
}
//todo neradi provjeravanje susjeda neznam zasto ali nedela
int Grid::susjedi(Dot *dot, int i) {
    int c = 0;
    if (i != 0) {
        auto left = dot - 1;
        if (left->IsAlive()) c++;
    }
    if (i != sizeX * (sizeY - 1)) {
        auto rignt = dot + 1;
        if (rignt->IsAlive()) c++;
    }
    if(i > sizeX) {
        auto top = dot - sizeX;
        auto topleft = top - 1;
        auto topright = top + 1;
        if (top->IsAlive()) c++;
        if (topleft->IsAlive()) c++;
        if (topright->IsAlive()) c++;
    }
    if (i < (sizeX * (sizeY - 1))) {
        auto bottom = dot + sizeX;
        auto botleft = bottom - 1;
        auto botright = bottom + 1;
        if (bottom->IsAlive()) c++;
        if (botleft->IsAlive()) c++;
        if (botright->IsAlive()) c++;
    }

    return c;
}

void Grid::next_gen() {
    old = dots;
    for (int i = 0; i < dots->size(); ++i) {

        int BrSusjeda = susjedi(&(*old)[i], i);
//
//        if (BrSusjeda == 2 && (*old)[i].IsAlive()) {}
//        else if (BrSusjeda == 3) (*dots)[i].Born();
//        else (*dots)[i].Die();

        if ((*dots)[i].IsAlive() && (BrSusjeda < 2 || BrSusjeda > 3)) (*dots)[i].Die();
        else if (BrSusjeda == 3) (*dots)[i].Born();
    }

}

Grid::~Grid() {
    delete dots;
}
