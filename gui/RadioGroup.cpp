#include "RadioGroup.hpp"

RadioGroup::RadioGroup( std::string id, double x, double y ) :
    Container( id, x, y, 0, 0 )
{
    m_drawing = true;
}


RadioGroup::~RadioGroup()
{

}


bool RadioGroup::mouseLeftDown()
{
    Container::mouseLeftDown();
    for( int i = 0; i < m_childs.size(); ++i )
        if( m_childs[i]->isPressed() )
        {
            for( int j = 0; j < m_childs.size(); ++j )
                m_childs[j]->setSelected( false );
            m_childs[i]->setSelected( true );
            break;
        }
}


void RadioGroup::draw()
{
    glPushMatrix();
        glTranslated( m_left, m_top, 0 );

        for( int i = 0; i < m_childs.size(); ++i )
            m_childs[i]->draw();

    glPopMatrix();
}

std::string RadioGroup::getStringValue() const
{
    for( int i = 0; i < m_childs.size(); ++i )
        if( m_childs[i]->isSelected() )
            return m_childs[i]->getID();
    return "";
}


