#include "Container.hpp"
#include "Gui.hpp"

Container::Container( std::string id, double x, double y, double width, double height ) :
    m_hovered( false ),
    m_focused( false ),
    m_pressed( false ),
    m_clicked( false ),
    m_top( y ),
    m_left( x ),
    m_width( width ),
    m_height( height ),
    m_id( id ),
    m_parent( NULL ),
    m_color( sf::Color::White ),
    m_gui( NULL )
{
    m_drawing = true;
}

Container::~Container()
{
}

void Container::draw(sf::RenderWindow &window)
{
    glPushMatrix();
        glTranslated( m_left, m_top, 0 );

        //draw children
        for( int i = 0; i < m_childs.size(); ++i )
            m_childs[ i ]->draw( window );

    glPopMatrix();


}


void Container::update( double dt )
{
    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->update( dt );
}

bool Container::mouseLeftDown()
{


    m_pressed = false;
    if( m_hovered )
        m_pressed = true;


    m_clicked = false;
    if( m_pressed )
        m_clicked = true;

    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->mouseLeftDown();

    return m_pressed;
}

bool Container::mouseLeftUp()
{
    if( m_hovered && m_clicked )
        m_clicked = true;
    else
        m_clicked = false;

    m_pressed = false;


    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->mouseLeftUp();

    return false;
}

void Container::mouseMoved( int x, int y )
{
    Vec2f pos = getPosition();
    m_hovered = false;
    if( x >= pos.x && y >= pos.y && x < pos.x + m_width && y < pos.y + m_height )
        m_hovered = true;

    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->mouseMoved( x, y );
}

bool Container::mouseWheelMoved( int delta )
{
    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->mouseWheelMoved( delta );
}

bool Container::keyPressed( unsigned int code )
{
    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->keyPressed( code );
}

bool Container::keyReleased( unsigned int code )
{
    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->keyReleased( code );
}

bool Container::textEntered( unsigned int code )
{
    for( int i = 0; i < m_childs.size(); ++i )
        m_childs[ i ]->textEntered( code );
}

void Container::handleEvents( const sf::Event& event )
{
    switch( event.type )
    {
        case sf::Event::MouseMoved:
            this->mouseMoved( event.mouseMove.x, event.mouseMove.y  );
            break;
        case sf::Event::MouseButtonPressed:
            this->mouseLeftDown();
            break;
        case sf::Event::MouseButtonReleased:
            this->mouseLeftUp();
            break;
        case sf::Event::KeyPressed:
            this->keyPressed( event.key.code );
            break;
        case sf::Event::TextEntered:
            this->textEntered( event.key.code );
            break;
        case sf::Event::MouseWheelMoved:
            this->mouseWheelMoved( event.mouseWheel.delta );
            break;
    }
}

void Container::addChild( ContainerPt child )
{
    m_childs.push_back( child );
//    child->registerGui( m_gui );
    child->setParent( this );
}

ContainerPt& Container::getChild( const std::string& id )
{
    for (auto it: m_childs){
        if (it->getID() == id) return it;
    }
}

void Container::setParent( ContainerPt parent )
{
    m_parent = parent;
}

void Container::setColor( const sf::Color& col )
{
    m_color = col;
}

void Container::setWidth( double width )
{
    m_width = width;
}
void Container::setHeight( double height )
{
    m_height = height;
}
void Container::setSize( double width, double height )
{
    m_width = width;
    m_height = height;
}
void Container::setPosition( double x, double y )
{
    m_left = x;
    m_top = y;
}

void Container::setDrawing(bool _drawing)
{
    m_drawing = _drawing;
}

void Container::setUpdating(bool _updating)
{
    m_updating = _updating;
}


const bool Container::isHovered() const
{
    return m_hovered;
}

const bool Container::isFocused() const
{
    return m_focused;
}

const bool Container::isPressed() const
{
    return m_pressed;
}

const bool Container::isClicked()
{
    if( m_clicked && !m_pressed )
    {
        m_clicked = false;
        return true;
    }
    return false;
}

Vec2f Container::getPosition() const
{
    if( m_parent == NULL )
        return Vec2f( m_left, m_top );
    Vec2f tmp = m_parent->getPosition();
    return Vec2f( tmp.x + m_left, tmp.y + m_top );
}

const std::string& Container::getID() const
{
    return m_id;
}

//void Container::registerGui( const GuiPt& gui )
//{
//    if( gui == NULL ) return;
//    if( this->m_gui != NULL ) return;
//    this->m_gui = gui;
//    if( this->getID() != "" )
//        m_gui->registerChild( this->getID(), this );
//    for( int i = 0; i < m_childs.size(); ++i )
//        m_childs[ i ]->registerGui( gui );
//}
