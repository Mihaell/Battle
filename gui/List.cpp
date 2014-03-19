#include "List.hpp"

List::List( std::string id, double x, double y, double width, double height ):
    Container( id, x, y, width, height )
{
    m_drawing = true;
}

List::~List()
{
}

void List::draw()
{
    glPushMatrix();
        glTranslated( m_left, m_top, 0 );
        //glViewport(0,0,400,300);
       // gluOrtho2D(0,40,0,30);

        for( int i = 0; i < m_childs.size(); ++i )
            m_childs[ i ]->draw();

    glPopMatrix();
}

bool List::mouseLeftUp()
{
    Container::mouseLeftUp();
    for( int i = 0; i < m_childs.size(); ++i )
    {
        m_childs[i]->setColor( sf::Color::White );
        if( m_childs[i]->isClicked() )
            m_selected = i;
    }
    if(m_selected<m_childs.size())
        m_childs[m_selected]->setColor(sf::Color::Yellow);
}

bool List::mouseLeftDown()
{
    Container::mouseLeftDown();
    for( int i = 0; i < m_childs.size(); ++i )
    {
        m_childs[i]->setColor( sf::Color::White );
        //if( m_childs[i]->isPressed() )
        //    m_selected = i;
    }
    if(m_selected<m_childs.size())
        m_childs[m_selected]->setColor(sf::Color::Yellow);
}
