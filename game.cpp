#include "game.h"
#include <cstdio>

Game::Game()
{
    field = new Board( 50, 50, 400, 400, 10, 10 );
    printf("Board initialised\n");
}

Game::~Game()
{

}


void Game::draw(sf::RenderWindow &window){
    field->draw( window );
}

void Game::update( double k ){


}
