#ifndef CUSTOMSTRUCTS_HPP
#define CUSTOMSTRUCTS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <cstdio>
#include "_inc_typ.hpp"

int toInt(std::string str);
std::string toString(int num);

namespace gl
{
    void drawTexQuad( double x, double y, double width, double height, bool whitecol = true );
    void drawTexQuad( double x, double y, double width, double height, double x1, double y1, double x2, double y2, bool whitecol = true );

    void drawRepTextQuad( double x, double y, double width, double height, double texwidth, double texheight, bool xrep = true, bool yrep = true ); //repeated
}

namespace rnd
{
    int getRandomInt( int lo, int hi );
    double getRandomdouble( double lo, double hi );
}

namespace math
{

    inline double sqr( double x )
    {
        return x * x;
    }

    struct rect
    {
        double x1, y1, x2, y2;
        rect( double _x1 = 0, double _y1 = 0, double _x2 = 0, double _y2 = 0 ) :
            x1( _x1 ), y1( _y1 ), x2( _x2 ), y2( _y2 ) {};
        inline bool isColliding( rect& rhs )
        {
            double _x1 = std::max( this->x1, rhs.x1 );
            double _y1 = std::max( this->y1, rhs.y1 );
            double _x2 = std::max( this->x2, rhs.x2 );
            double _y2 = std::max( this->y2, rhs.y2 );
            return ( _x1 <= _x2 && _y1 <= _y2 );
        }
    };

    struct circle
    {
        double x, y, r;
        circle( double _x = 0, double _y = 0, double _r = 0 ) :
            x( _x ), y( _y ), r( _r ) {};
        inline bool isColliding( circle& rhs )
        {
            return ( sqr(rhs.x - x) + sqr(rhs.y - y) <= sqr(rhs.r + r) );
        }
    };
}

namespace txt
{
    enum aligns
    {
        ALIGN_LEFT,
        ALIGN_CENTER,
        ALIGN_RIGHT
    };

    void draw(
        sf::RenderWindow& window,
        sf::String text,
        const sf::Font& font,
        double x,
        double y,
        double size = 12,
        const int& align = ALIGN_LEFT,
        const sf::Color& col = sf::Color::White,
        const int& style = sf::Text::Regular
    );

    double getCharPos(
        sf::String text,
        const sf::Font& font,
        int idx,
        double size = 12,
        const int& align = ALIGN_LEFT,
        const int& style = sf::Text::Regular
    );

}

#endif // CUSTOMSTRUCTS_HPP
