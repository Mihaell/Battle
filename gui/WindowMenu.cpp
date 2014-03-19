#include "WindowMenu.hpp"


WindowMenu::WindowMenu(std::string id, double width, double height) :
    Container( id, ( App::internWidth - width ) * 0.5, ( App::internHeight - height ) * 0.5, width, height )
{/*
    double x = ( App::internWidth - width ) * 0.5;
    double y = ( App::internHeight - height ) * 0.5;

    Container( id, x, y, width, height );*/

    m_drawing = true;
}


void WindowMenu::draw()
{
    glPushMatrix();
        glTranslated( m_left, m_top, 0 );

       // App::m_assetManager->loadTexture( "data/img/gui/windowBorders.png" );
      //  App::m_assetManager->loadTexture( "data/img/gui/windowPaperBackground.png" );

       // App::m_assetManager->useTexture( "data/img/gui/windowPaperBackground.png" );
        //gl::drawRepTextQuad( 0, 0, m_width, m_height, 64,64 );


        glPushMatrix();
            glTranslated( -10, -10, 0 );

            double width = m_width + 20;
            double height = m_height + 20;
            const int size = 96;

           // App::m_assetManager->useTexture( "data/img/gui/windowBorders.png" );

            /*gl::drawTexQuad( 0, 0, size, size, 0, 0, 0.48, 0.48 );
            gl::drawTexQuad( width - size, 0, size, size, 0.52, 0, 1, 0.48 );
            gl::drawTexQuad( width - size, height - size, size, size, 0.52, 0.52, 1, 1 );
            gl::drawTexQuad( 0, height - size, size, size, 0, 0.52, 0.48, 1 );

            gl::drawTexQuad( 0, size, size, height - 2*size, 0, 0.495, 0.48, 0.505 );
            gl::drawTexQuad( width - size, size, size, height - 2*size, 0.52, 0.495, 1, 0.505 );
            gl::drawTexQuad( size, 0, width - 2*size, size, 0.495, 0, 0.505, 0.48 );
            gl::drawTexQuad( size, height - size, width - 2*size, size, 0.495, 0.52, 0.505, 1 );*/

        glPopMatrix();

    glPopMatrix();
}


