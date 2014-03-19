#include "board.h"
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

    for (int i=0; i<n; i++){
        for (int j=0; j<=m/3; j++){
            data[i][j] = new Unit("img/figther.png");
            data[i][j]->setPosition( j*50 + x, i*50 + y );
        }
    }
}

Board::~Board()
{

}

void Board::draw(sf::RenderWindow &window){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            window.draw( border[i][j] );
            if ( data[i][j] == NULL ) continue;
            window.draw( *data[i][j] );
        }
    }

}

void Board::update( double k ){

}
