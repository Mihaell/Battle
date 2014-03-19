#ifndef SCROLLABLECONTAINER_HPP
#define SCROLLABLECONTAINER_HPP

#include "Container.hpp"

class ScrollableContainer : public Container
{
    public:

        ScrollableContainer( std::string id = "", double x = 0, double y = 0, double width = 0, double height = 0, double contwidth = 0, double contheight = 0 );
        virtual ~ScrollableContainer();

        virtual void draw();
        virtual void update( double dt );

        virtual bool mouseLeftDown();
        virtual bool mouseLeftUp();
        virtual void mouseMoved( int x, int y );
        virtual bool mouseWheelMoved( int delta );
/*
        virtual bool keyPressed( unsigned int code );
        virtual bool keyReleased( unsigned int code );
        virtual bool textEntered( unsigned int code );
*/

        virtual void addChild( ContainerPt child );

    protected:

        ContainerPt m_content;
        double m_offsetX;
        double m_offsetY;
        double m_contentWidth;
        double m_contentHeight;

};

#endif // SCROLLABLECONTAINER_HPP

