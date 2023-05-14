//
// Created by fran on 07.05.23..
//

#ifndef GAMEOFLIFE_DOT_H
#define GAMEOFLIFE_DOT_H

#include <SFML/Graphics.hpp>

class Dot {
private:
    sf::RectangleShape dot;
    bool alive = false;


public:
    Dot();
    ~Dot();

    void Born();

    void FirstBorn(int spawn_rate);

    void Die();

    void Switch();

    bool IsAlive() const;

    friend bool operator==(const Dot &left, const Dot &right);

    void move(int x, int y);

    void draw(sf::RenderWindow &window);
};

#endif //GAMEOFLIFE_DOT_H
