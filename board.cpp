#include "board.h"
#include "gui/Button.hpp"
#include "effects/effect.h"
#include "game.h"
#include <cstdio>
#include <algorithm>
#include <iostream>

Board::Board(double _x, double _y, double _w, double _h, int _n, int _m)
{
    x = _x; y = _y; w = _w; h = _h; n = _n; m = _m;

    printf("Board %dX%d\n", n, m);

    borderTex.loadFromFile( "img/border.png" );

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            data[i][j] = NULL;
            if ( j>m/3 && j<m/3*2 ) continue;
            border[i][j].setTexture( borderTex );
            border[i][j].setPosition( j*50 + x, i*50 + y );
        }
    }

    std::string units[2] = { "img/figther.png", "img/mage.png" };

    for (int i=0; i<n; i++){
        for (int j=0; j<=m/3; j++){
            data[i][j] = new Unit(units[rand()%2]);
            data[i][j]->setPosition( j*50 + x, i*50 + y );
        }
    }

    gui = new Container();
    for (int i=0; i<=m/3; i++){
        Button* tmp = new Button("BtnUP" + toString(i), "", x + i*50 + 12.5, y - 50 + 12.5, 25, 25);
        tmp->connectCallback( [this, i](void){ return this->moveColumn( i, 1 ); } );
        gui->addChild( tmp );
    }
    for (int i=0; i<=m/3; i++){
        Button* tmp = new Button("BtnDOWN" + toString(i), "", x + i*50 + 12.5, y + 50*m + 12.5, 25, 25);
        tmp->connectCallback( [this, i](void){ return this->moveColumn( i, -1 ); } );
        gui->addChild( tmp );
    }
    for (int i=0; i<n; i++){
        Button* tmp = new Button("BtnATTACK" + toString(i), "", x + (n/2)*50 - 12.5, y + 50*i + 12.5, 25, 25);
        tmp->connectCallback( [this, i](void){ return this->attackRow( i ); } );
        gui->addChild( tmp );
    }
}

Board::~Board()
{

}

void Board::draw(sf::RenderWindow &window){

    window.pushGLStates();

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            window.draw( border[i][j] );
            if ( data[i][j] == NULL ) continue;
            window.draw( *data[i][j] );
        }
    }

    window.popGLStates();

    gui->draw( window );
}

void Board::update( double k ){

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (data[i][j] == NULL) continue;
            double dx = ( ( j*50 + x ) - data[i][j]->getPosition().x ) / (rand()%5+10);
            double dy = ( ( i*50 + y ) - data[i][j]->getPosition().y ) / (rand()%5+10);
            data[i][j]->move( dx, dy );
        }
    }

    gui->update( k );
}

void Board::handleEvent(sf::Event& event)
{
    gui->handleEvents( event );
}

void Board::attackRow(int x){
    printf("napadam red %d\n", x);

//    std::cout << gui->getChild( "BtnATTACK" + toString(x) )->m_width << std::endl;
    Game::effManager->addEffect(new Effect( &( gui->getChild( "BtnATTACK" + toString(x) )->m_width ), Efekt::LINEAR_DECREASE ) );
    Game::effManager->addEffect(new Effect( &( gui->getChild( "BtnATTACK" + toString(x) )->m_left ), Efekt::LINEAR_INCREASE ) );
    gui->getChild( "BtnATTACK" + toString(x) )->m_updating = false;
//    std::cout << gui->getChild( "BtnATTACK" + toString(x) )->m_width << std::endl;
}

void Board::moveColumn(int x, int off)
{
    if (off == 1){
        for (int i=0; i<n-1; i++){
            std::swap( data[i][x], data[i+1][x] );
        }
    } else
    if (off == -1){
        for (int i=n-1; i>0; i--){
            std::swap( data[i][x], data[i-1][x] );
        }
    }

    printf("pomicem %d stupac\n", x);
    printf("pomicem prema %d\n", off);
}
