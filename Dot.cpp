//
// Created by fran on 07.05.23..
//
#include <random>
#include "Dot.h"

void Dot::draw(sf::RenderWindow &window) {
    window.draw(dot);
}

void Dot::move(int x, int y) {
    dot.move(sf::Vector2f(x, y));
}

Dot::Dot() {
    dot.setSize(sf::Vector2f(10.f, 10.f));
    dot.setFillColor(sf::Color::Black);
    dot.setOutlineColor(sf::Color::White);
    dot.setOutlineThickness(0.6);
}

Dot::~Dot() {

}

void Dot::Born() {
    alive = true;
    dot.setFillColor(sf::Color::White);
}

void Dot::Die() {
    alive = false;
    dot.setFillColor(sf::Color::Black);
}

bool Dot::IsAlive() {
    return alive;
}

void Dot::Switch() {
    if (IsAlive()) Die();
    else Born();
}

bool operator==(const Dot &left, const Dot &right) {
    return left.alive == right.alive;
}

void Dot::FirstBorn(int spawn_rate) {
    if (rand() % 100 + 1 <= spawn_rate)
        Born();
}
