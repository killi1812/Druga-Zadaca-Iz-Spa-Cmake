#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main() {
    cout << "Bok";
    int a;
    cin >>a;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game Of Life");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
    return 0;
}