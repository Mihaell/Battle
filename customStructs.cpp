#include "customStructs.hpp"

#include <sstream>

int toInt(std::string str){
    std::string raw = str;

    std::stringstream stream(raw);

    int num;

    stream >> num;

    return num;
}

std::string toString(int num)
{
    std::string rez;
    while (num>0)
    {
        rez += (num%10)+'0';
        num /= 10;
    }
    reverse(rez.begin(),rez.end());

    if (rez.size() == 0) return "0";

    return rez;
}

namespace gl
{
    void drawTexQuad( double x, double y, double width, double height, bool whitecol )
    {
        glPushMatrix();
            glTranslated( x, y, 0 );

            if( whitecol )
                glColor4f( 1, 1, 1, 1 );

            glEnable( GL_TEXTURE_2D );
            glBegin( GL_QUADS );
                glTexCoord2d( 0, 0 );   glVertex2d( 0, 0 );
                glTexCoord2d( 1, 0 );   glVertex2d( width, 0 );
                glTexCoord2d( 1, 1 );   glVertex2d( width, height );
                glTexCoord2d( 0, 1 );   glVertex2d( 0, height );
            glEnd();
            glDisable( GL_TEXTURE_2D );

        glPopMatrix();
    }

    void drawTexQuad( double x, double y, double width, double height, double x1, double y1, double x2, double y2, bool whitecol )
    {
        glPushMatrix();
            glTranslated( x, y, 0 );

            if( whitecol )
                glColor4d( 1, 1, 1, 1 );

            glEnable( GL_TEXTURE_2D );
            glBegin( GL_QUADS );
                glTexCoord2d( x1, y1 );     glVertex2d( 0, 0 );
                glTexCoord2d( x2, y1 );     glVertex2d( width, 0 );
                glTexCoord2d( x2, y2 );     glVertex2d( width, height );
                glTexCoord2d( x1, y2 );     glVertex2d( 0, height );
            glEnd();
            glDisable( GL_TEXTURE_2D );

        glPopMatrix();
    }

    void drawRepTextQuad( double x, double y, double width, double height, double texwidth, double texheight, bool xrep, bool yrep )
    {
        glPushMatrix();
            glTranslated( x, y, 0 );

            double xtex = 1.0, ytex = 1.0;
            double wtex = texwidth, htex = texheight;

            if( xrep )
            {
                xtex = width / texwidth;
                wtex = width;
            }
            if( yrep )
            {
                ytex = height / texheight;
                htex = height;
            }

            drawTexQuad( 0, 0, wtex, htex, 0, 0, xtex, ytex );

        glPopMatrix();
    }
}

namespace txt
{
    void draw( sf::RenderWindow& window, sf::String text, const sf::Font& font, double x, double y, double size, const int& align, const sf::Color& col, const int& style )
    {
        window.pushGLStates();
        sf::Text txt;
        txt.setString( text );
        txt.setFont( font );
        txt.setCharacterSize( (int)size );
        txt.setColor( col );
        txt.setStyle( style );

        double bound = txt.getLocalBounds().width;
        switch( align )
        {
            case ALIGN_CENTER:
                x -= bound * 0.5;
                break;
            case ALIGN_RIGHT:
                x -= bound;
                break;
        }

        txt.setPosition( (int)x, (int)y );
        window.draw( txt );

        window.popGLStates();
    }

    double getCharPos( sf::String text, const sf::Font& font, int idx, double size, const int& align, const int& style )
    {
        sf::Text txt;
        txt.setString( text );
        txt.setFont( font );
        txt.setCharacterSize( size );
        txt.setStyle( style );

        double ret = txt.findCharacterPos( idx ).x;
        double width = txt.getLocalBounds().width;
        switch( align )
        {
            case ALIGN_CENTER:
                ret -= width * 0.5;
                break;
            case ALIGN_RIGHT:
                ret -= width;
                break;
        }

        return ret;
    }
}
