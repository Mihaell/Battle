#include "RadioButton.hpp"
#include "Label.hpp"

RadioButton::RadioButton( std::string id, std::string val, double x, double y ) :
    Container( id, x, y, 24, 16 ),
    m_selected( false ),
    m_label( NULL )
{
    m_label = new Label( id + "_label", val, m_width, -1, 160 );
    m_drawing = true;
    this->addChild( m_label );
}

void RadioButton::draw()
{
    glPushMatrix();
        glTranslatef( m_left, m_top, 0 );

        App::myAssetManager->useTexture( "radio_button" );
        gl::drawTexQuad( 0, 0, m_height, m_height, 0, 0.5 * m_selected, 1, 0.5 * (m_selected + 1) );


        m_label->draw();

    glPopMatrix();
}

void RadioButton::update( double dt )
{
}

void RadioButton::mouseMoved( int x, int y )
{
    Container::mouseMoved( x, y );
    m_hovered |= m_label->isHovered();
    if( m_hovered ) m_label->setColor( sf::Color::Blue );
    else m_label->setColor( sf::Color::Black );
}

bool RadioButton::mouseLeftDown()
{
    m_pressed = false;
    if( m_hovered )
        m_pressed = true;
    return false; //????!
}


void RadioButton::setSelected( bool selected )
{
    m_selected = selected;
}
