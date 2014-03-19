#include "Gui.hpp"

Gui::Gui()
{
    m_root = new Container( "GUI_ROOT_CONTAINER", 0, 0, 600, 600 );
}

Gui::~Gui()
{
}

void Gui::draw(sf::RenderWindow &window)
{
    m_root->draw( window );
}


void Gui::update( double dt )
{
    m_root->update( dt );
}

void Gui::handleEvents( const sf::Event& event )
{
    m_root->handleEvents( event );
}


ContainerPt Gui::addChild( ContainerPt child )
{
    child->registerGui( this );
    m_root->addChild( child );
    return child;
}

void Gui::registerChild( const std::string& id, ContainerPt child )
{
    if( id != "" )
        m_childs[ id ] = child;
}

ContainerPt& Gui::getChild( const std::string& id )
{
    return m_childs[ id ];
}
