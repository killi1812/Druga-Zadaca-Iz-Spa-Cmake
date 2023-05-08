#include <SFML/Graphics.hpp>
#include <ctime>
#include <random>
#include "Grid.h"
#include <iostream>
using namespace std;



int main() {
    srand(time(nullptr));
    double speed;
    int spawn_rate;
    cout << "Enter Spawn Rate 1 - 100: ";
    cin >> spawn_rate;
    cout << "Enter Time Between cycles in ms: ";
    cin >> speed;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game Of Life");
    Grid grid(&window, speed, spawn_rate);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        grid.draw();
        window.display();
    }

    return 0;
}