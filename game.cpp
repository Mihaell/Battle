#include "game.h"
#include <cstdio>
#include <SFML/OpenGL.hpp>

EffectManager* Game::effManager = new EffectManager;

Game::Game()
{
    field = new Board( 50, 50, 400, 400, 10, 10 );
    printf("Board initialised\n");
}

Game::~Game()
{

}


void Game::draw(sf::RenderWindow &window){

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, 600, 600, 0.0 );

    glMatrixMode( GL_MODELVIEW );
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    glLoadIdentity();
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    field->draw( window );

    glDisable( GL_BLEND );
    glDisable( GL_TEXTURE_2D );
}

void Game::update( double k ){
    field->update( k );
    effManager->update( k );
}

void Game::handleEvent(sf::Event &event){
    field->handleEvent( event );
}
