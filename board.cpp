#include "board.h"
#include "gui/Button.hpp"
#include <cstdio>

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
    gui->update( k );
}

void Board::handleEvent(sf::Event& event)
{
    gui->handleEvents( event );
}


void Board::moveColumn(int x, int off)
{
    printf("pomicem %d stupac\n", x);
    printf("pomicem prema %d\n", off);
}
