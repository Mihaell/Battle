#include "TextEdit.hpp"

TextEdit::TextEdit( std::string id, std::string val, double x, double y, double width, double height, double size, int align ) :
    Container( id, x, y, width, height ),
    m_cursor( 0 ),
    m_align( align ),
    m_size( size ),
    m_allowEdit( false )
{
    m_value = sf::String( val );
    m_drawing = true;
}

void TextEdit::draw()
{
    glPushMatrix();
        glTranslatef( m_left, m_top, 0 );

        const sf::Font& font = App::myAssetManager->getFont( "nanum" );
        double le = txt::getCharPos( m_value, font, m_cursor, m_size, m_align ) + m_width * ( (double)m_align / 2.0 );

        glBegin( GL_LINES );
            glColor3f( 1, 1, 1 );
            glVertex2f( 0, 0 );
            glVertex2f( m_width, 0 );
            glVertex2f( m_width, 0 );
            glVertex2f( m_width, m_height );
            glVertex2f( m_width, m_height );
            glVertex2f( 0, m_height );
            glVertex2f( 0, m_height );
            glVertex2f( 0, 0 );

            if( m_allowEdit )
            {
                glVertex2f( le, 5 );
                glVertex2f( le, 20 );
            }

        glEnd();

        for( int i = 0; i < m_childs.size(); ++i )
            m_childs[ i ]->draw();

        const Vec2f pos = this->getPosition();
        const double ypos = pos.y + m_height * 0.5 - m_size * 0.65;

        switch( m_align )
        {
            case txt::ALIGN_CENTER:
                txt::draw( *App::window, m_value, font, pos.x + m_width * 0.5, ypos, m_size, txt::ALIGN_CENTER );
                break;
            case txt::ALIGN_RIGHT:
                txt::draw( *App::window, m_value, font, pos.x + m_width, ypos, m_size, txt::ALIGN_RIGHT );
                break;
            default:
        txt::draw( *App::window, m_value, font, pos.x, ypos, m_size, txt::ALIGN_LEFT );
                break;
        }

    glPopMatrix();
}

bool TextEdit::mouseLeftDown()
{
    Container::mouseLeftDown();
    m_focused = false;
    m_allowEdit = false;
    if( !m_pressed )
        return false;

    m_focused = true;
    m_allowEdit = true;

    sf::Vector2i pos = sf::Mouse::getPosition( *App::window );
    double x = getPosition().x;
    const sf::Font& font = App::myAssetManager->getFont( "nanum" );

    for( m_cursor = 0; m_cursor < m_value.getSize(); )
    {
        double le = txt::getCharPos( m_value, font, m_cursor, m_size, m_align ) + m_width * ( (double)m_align / 2.0 );
        if( le + x > pos.x )
            break;
        ++m_cursor;
    }

    return true;
}

bool TextEdit::keyPressed( unsigned int code )
{
    if( m_focused )
    {
        if( m_allowEdit )
        {
            if( code == sf::Keyboard::BackSpace && m_cursor > 0 )
            {
                m_value.erase( m_cursor - 1, 1 );
                --m_cursor;
            }
            if( code == sf::Keyboard::Delete && m_cursor < m_value.getSize() )
            {
                m_value.erase( m_cursor, 1 );
            }
            if( code == sf::Keyboard::Left && m_cursor > 0 )
            {
                --m_cursor;
            }
            if( code == sf::Keyboard::Right && m_cursor < m_value.getSize() )
            {
                ++m_cursor;
            }
        }
    }
}

bool TextEdit::textEntered( unsigned int code )
{
    if( m_focused && m_allowEdit )
    {
        if( m_value.getSize() < 20 && code != 8 && code != 13 /*&& code != 32*/ && code != 127 )
        {
            m_value.insert( m_cursor, (char)code );
            ++m_cursor;
        }
    }
}

std::string TextEdit::getStringValue() const
{
    return m_value.toAnsiString();
}
