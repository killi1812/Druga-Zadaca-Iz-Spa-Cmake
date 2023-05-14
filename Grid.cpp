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
int Grid::susjedi(std::array<Dot, 108 * 192> *dot, int i) {
    int c = 0;

    if (i != 0 && i % sizeX != 0) {
        auto left = i - 1;

        if (dot->at(left).IsAlive()) {
            c++;
        }
    }
    if (i % sizeX != (sizeX - 1)) {
        auto rignt = i + 1;
        if (dot->at(rignt).IsAlive()) c++;
    }
    //nedela  cekiranje iznad
    if (i >= sizeX) {
        auto top = i - sizeX;
        if (dot->at(top).IsAlive()) {
            c++;
        }

        if (i % sizeX != 0) {
            auto topleft = top - 1;
            if (dot->at(topleft).IsAlive()) c++;
        }

        if (i % sizeX != (sizeX - 1)) {
            auto topright = top + 1;
            if (dot->at(topright).IsAlive()) c++;
        }
    }

    if (i <= (sizeX * (sizeY - 1) - 1)) {
        auto bottom = i + sizeX;
        if (dot->at(bottom).IsAlive()) c++;
        if (i % sizeX != 0) {

            auto botleft = bottom - 1;
            if (dot->at(botleft).IsAlive()) c++;
        }
        if (i % sizeX != (sizeX - 1)) {

            auto botright = bottom + 1;
            if (dot->at(botright).IsAlive()) c++;
        }
    }

    return c;
}

void Grid::next_gen() {
    for(int i = 0; i < dots->size();i++){
        (*old)[i] =  (*dots)[i];
    }
    int counter = 0, died = 0;
    for (int i = 0; i < dots->size(); ++i) {

        int BrSusjeda = susjedi(old, i);

        //        if (BrSusjeda == 2 && (*old)[i].IsAlive()) {}
        //        else if (BrSusjeda == 3) (*dots)[i].Born();
        //        else (*dots)[i].Die();

        if ((*dots)[i].IsAlive() && (BrSusjeda < 2 || BrSusjeda > 3)) {
            (*dots)[i].Die();
            died++;
        } else if (BrSusjeda == 3) {
            (*dots)[i].Born();
            counter++;
        }

    }
}

Grid::~Grid() {
    delete dots;
}
