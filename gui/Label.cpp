#include "Label.hpp"

Label::Label( std::string id, std::string val, double x, double y, double width, int align, double size ) :
    Container( id, x, y, width, size * 1.4 ),
    m_align( align ),
    m_size( size )
{
    m_value = sf::String( val );
    m_drawing = true;
}

Label::~Label()
{
}

void Label::draw()
{
    Vec2f pos = getPosition();

    glPushMatrix();
        glTranslatef( m_left, m_top, 0 );

        const sf::Font& font = App::myAssetManager->getFont( "nanum" );
        switch( m_align )
        {
            case txt::ALIGN_CENTER:
                txt::draw( *App::window, m_value, font, pos.x + m_width * 0.5, pos.y, m_size, m_align, m_color );
                break;
            case txt::ALIGN_RIGHT:
                txt::draw( *App::window, m_value, font, pos.x + m_width, pos.y, m_size, m_align, m_color );
                break;
            default:
                txt::draw( *App::window, m_value, font, pos.x, pos.y, m_size, m_align, m_color );
                break;
        }

        for( int i = 0; i < m_childs.size(); ++i )
        {
            m_childs[ i ]->draw();
        }

    glPopMatrix();
}

void Label::setValue( std::string val )
{
    m_value = sf::String( val );
}

std::string Label::getStringValue() const
{
    return m_value.toAnsiString();
}
