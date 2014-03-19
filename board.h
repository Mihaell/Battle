#ifndef BOARD_H
#define BOARD_H

#include "unit.h"
#include <SFML/Graphics.hpp>
#include "gui/Container.hpp"

class Board
{
    public:
        Board(double _x, double _y, double _w, double _h, int _n, int _m);
        ~Board();

        void draw(sf::RenderWindow &window);
        void update( double k );

        void handleEvent( sf::Event &event );

    protected:
    private:

        void moveColumn( int x, int off );

        Unit* data[50][50];
        sf::Sprite border[50][50];

        double x, y;
        double w, h;
        int n, m;

        sf::Texture borderTex;

        Container* gui;

};


#endif // BOARD_H

