#include <SFML/Graphics.hpp>
#include "game.h"
#include <cstdio>

int main(){

    sf::RenderWindow window(sf::VideoMode(600, 600), "Battle");
    Game myGame;
    sf::Texture texture;
    texture.loadFromFile("img/figther.png");
    while ( window.isOpen() ){

        sf::Event event;

        while ( window.pollEvent( event ) ){
            switch ( event.type )
            {
            case sf::Event::Closed:
                window.close();
                break;

            default:
                myGame.handleEvent( event );
                break;
            }
        }

        window.clear(sf::Color(255, 255, 255));
        myGame.update( 0.2 );
        myGame.draw( window );
        window.display();
    }


    return 0;
}
