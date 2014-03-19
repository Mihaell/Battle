#include "ScrollableContainer.hpp"

ScrollableContainer::ScrollableContainer( std::string id, double x, double y, double width, double height, double contwidth, double contheight ) :
    Container( id, x, y, width, height ),
    m_content( NULL ),
    m_offsetX( 0 ),
    m_offsetY( 0 ),
    m_contentWidth( contwidth ),
    m_contentHeight( contheight )
{
    if( m_contentWidth < m_width ) m_contentWidth = m_width;
    if( m_contentHeight < m_height ) m_contentHeight = m_height;

    m_content = new Container( id + "_content", 0, 0, m_contentWidth, m_contentHeight );
    m_content->setParent(this);
    m_childs.push_back( m_content );
}


ScrollableContainer::~ScrollableContainer()
{
}

void ScrollableContainer::draw()
{
    glPushMatrix();
        glTranslated( m_left, m_top, 0 );

        Vec2f pos = getPosition();
        App::myCameraManager->setView( pos.x, pos.y, m_width, m_height );
        m_content->draw();
        App::myCameraManager->setDefaultView();

    glPopMatrix();
}

void ScrollableContainer::update( double dt )
{
    m_content->update( dt );
}

void ScrollableContainer::addChild( ContainerPt child )
{
    m_content->addChild( child );
}

void ScrollableContainer::mouseMoved( int x, int y )
{
    Vec2f pos = getPosition();
    m_hovered = false;
    if( x >= pos.x && y >= pos.y && x < pos.x + m_width && y < pos.y + m_height )
        m_hovered = true;

    if( m_hovered )
        m_content->mouseMoved( x, y );
}

bool ScrollableContainer::mouseLeftDown()
{
    if( m_hovered )
    {
        m_content->mouseLeftDown();
    }
}

bool ScrollableContainer::mouseLeftUp()
{
    if( m_hovered )
    {
        m_content->mouseLeftUp();
    }
}

bool ScrollableContainer::mouseWheelMoved(int delta)
{
    delta *= 3;
    if( m_hovered )
    {
        m_offsetY+=delta;
        m_content->setPosition(0,m_offsetY);
    }
}
