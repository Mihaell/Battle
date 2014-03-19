#include "Button.hpp"

Button::Button( std::string id, std::string val, double x, double y, double width, double height, int align, double size ) :
    Container( id, x, y, width, height ),
//    m_clicked( false ),
    m_align( align ),
    m_size( size ),
    del( 1.0 )
{
    m_value = sf::String( val );
    m_drawing = true;
    m_updating = true;
    m_font.loadFromFile( "font/NanumGothic.ttf" );
}

void Button::draw( sf::RenderWindow &window )
{
    if (!m_drawing) return;

    glPushMatrix();
        glTranslatef( m_left, m_top, 0 );

        glBegin( GL_LINES );
            glColor3f( 0, 1 - del, 0  );
            glVertex2f( 0, 0 );
            glVertex2f( m_width, 0 );
            glVertex2f( m_width, 0 );
            glVertex2f( m_width, m_height );
            glVertex2f( m_width, m_height );
            glVertex2f( 0, m_height );
            glVertex2f( 0, m_height );
            glVertex2f( 0, 0 );
        glEnd();

        for( int i = 0; i < m_childs.size(); ++i )
            m_childs[ i ]->draw( window );

    glPopMatrix();

    const Vec2f pos = this->getPosition();
    const double ypos = pos.y + m_height * 0.5 - m_size * 0.65;
    const sf::Font& font = m_font;

    switch( m_align )
    {
        case txt::ALIGN_CENTER:
            txt::draw( window, m_value, font, pos.x + m_width * 0.5, ypos, m_size, txt::ALIGN_CENTER );
            break;
        case txt::ALIGN_RIGHT:
            txt::draw( window, m_value, font, pos.x + m_width, ypos, m_size, txt::ALIGN_RIGHT );
            break;
        default:
            txt::draw( window, m_value, font, pos.x, ypos, m_size, txt::ALIGN_LEFT, sf::Color::White, sf::Text::Italic | sf::Text::Bold );
            break;
    }
}

void Button::update( double dt )
{
    if (!m_updating) return;

    if( m_hovered ) del = 0;
    else del += dt * 2;
    if( del > 1 ) del = 1;

    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->update( dt );
}

bool Button::mouseLeftDown()
{
    bool ret = Container::mouseLeftDown();

    return ret;
}

bool Button::mouseLeftUp()
{
    bool ret = Container::mouseLeftUp();
    //if( m_clicked && m_hovered ) // haha, problem...
    if( isClicked() )
    {
        callCallback();
    }
    return ret;
}


void Button::setValue( std::string val )
{
    m_value = sf::String( val );
}

std::string Button::getValue() const
{
    std::string ret = "";
    return ret;
}

void Button::callCallback()
{
    if (m_cb && m_updating) m_cb();
    return;
}
/*
bool Button::isClicked()
{
    if( m_clicked && !m_pressed )
    {
        m_clicked = false;
        return true;
    }
    return false;
}*/

std::string Button::getStringValue() const
{
    return m_value.toAnsiString();
}
