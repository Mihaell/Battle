#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "../_inc_typ.hpp"
#include "../Interfaces/ICall.h"

//#include "Gui.hpp"

class Container: public ICall
{
    public:

        Container( std::string id = "", double x = 0, double y = 0, double width = 0, double height = 0 );
        virtual ~Container();

        virtual void draw(sf::RenderWindow &window);
        virtual void update( double dt );

        void handleEvents( const sf::Event& event );

        virtual bool mouseLeftDown();
        virtual bool mouseLeftUp();
        virtual void mouseMoved( int x, int y );
        virtual bool mouseWheelMoved( int delta );

        virtual bool keyPressed( unsigned int code );
        virtual bool keyReleased( unsigned int code );
        virtual bool textEntered( unsigned int code );

        virtual void addChild( ContainerPt child );
        virtual ContainerPt& getChild( const std::string& id );
        virtual void setParent( ContainerPt parent );

        void setColor( const sf::Color& col );

        void setWidth( double width );
        void setHeight( double height );
        void setSize( double width, double height );
        void setPosition( double x, double y );

        const bool isHovered() const;
        const bool isFocused() const;
        const bool isPressed() const;
        const bool isClicked();

        const std::string& getID() const;

        Vec2f getPosition() const; // absolute position

//        void registerGui( const GuiPt& gui );

        // extend...
        //virtual bool isClicked(){};
        virtual void setValue( std::string ){};
        virtual void setValue( int ){};
        virtual void setDrawing( bool );
        virtual void setUpdating( bool );
        virtual void setSelected( bool selected ) {};
        //virtual void addItem( std::string id, std::string value ) {}; //list, maybe radiobutton?
        virtual void setCharacterSize( double size ) {};

        virtual std::string getStringValue() const {};
        virtual int getIntValue() const{};
        virtual bool isSelected() const{};

    protected:

        bool m_hovered;
        bool m_focused;
        bool m_pressed;
        bool m_clicked;

        bool m_drawing;
        bool m_updating;

        double m_top;
        double m_left;
        double m_width;
        double m_height;

        ContainerPt m_parent;
        std::vector< ContainerPt > m_childs;
        std::string m_id;

        sf::Color m_color;

        GuiPt m_gui;

    private:
};

#endif // CONTAINER_HPP
