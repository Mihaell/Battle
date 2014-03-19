#include "HorizontalSlider.hpp"

HorizontalSlider::HorizontalSlider( std::string id, float x, float y, float width, int lo, int hi, int step ) :
    Container( id, x, y, width, 10 ),
    m_minVal( lo ),
    m_maxVal( hi ),
    m_step( step ),
    m_value( lo )
{
}

HorizontalSlider::~HorizontalSlider()
{
}

void HorizontalSlider::draw()
{
    glPushMatrix();
    //glLoadIdentity();
        glTranslated( m_left, m_top, 0.0 );

        const float sz = 4;
        const float le = float( m_value - m_minVal ) / ( m_maxVal - m_minVal ) * (m_width-2*sz) + sz;

        glColor3d(1, 1, 1);
        glBegin( GL_LINES );
            glVertex2d( 0, sz );
            glVertex2d( m_width, sz );
        glEnd();

        glBegin(GL_QUADS);
            glVertex2d( le - sz, 0 );
            glVertex2d( le + sz, 0 );
            glVertex2d( le + sz, 8 );
            glVertex2d( le - sz, 8 );
        glEnd();

        // Draw all child Containers
        for (int i=0; i<m_childs.size(); i++)
        {
            m_childs[i]->draw();
        }

    glPopMatrix();
}

void HorizontalSlider::setRange( int lo, int hi, int step )
{
    m_minVal = lo;
    m_maxVal = hi;
    if( step > 0 )
        m_step = step;
}


void HorizontalSlider::mouseMoved( int x, int y )
{
    Container::mouseMoved( x, y );
    Vec2f pos = getPosition();
    if( m_pressed )
    {
        float tmp = ( x - pos.x ) / m_width * ( m_maxVal - m_minVal ) + m_minVal;
        m_value = (int)tmp;
        if( m_value < m_minVal ) m_value = m_minVal;
        if( m_value > m_maxVal ) m_value = m_maxVal;
    }
}

bool HorizontalSlider::mouseLeftDown()
{
    Container::mouseLeftDown();
    if( m_pressed && !m_focused )
    {
        m_focused = true;
    }
    else m_focused = false;
}

bool HorizontalSlider::mouseLeftUp()
{
    Container::mouseLeftUp();
    if( !m_hovered )
        m_focused = false;
}

bool HorizontalSlider::mouseWheelMoved(int delta)
{
    if( m_hovered && !m_focused )
        m_focused = true;

    if( m_focused )
    {
        m_value += delta;
        if( m_value < m_minVal ) m_value = m_minVal;
        if( m_value > m_maxVal ) m_value = m_maxVal;
    }
}

/*
bool HorizontalSlider::keyPressed(sf::Event::KeyEvent key)
{
    if( m_focused )
    {

    }

    if( isFocused )
    {
        if( key.code == sf::Keyboard::Left )
            m_value -= step;
        if( key.code == sf::Keyboard::Right )
            m_value += step;

        if( m_value < minVal ) m_value = minVal;
        if( m_value > maxVal ) m_value = maxVal;

        return true;
    }
    return false;
}*/
