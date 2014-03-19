#ifndef TEXTEDIT_HPP
#define TEXTEDIT_HPP

#include "Container.hpp"

class TextEdit : public Container
{
    public:

        TextEdit( std::string id = "", std::string val = "", double x = 0, double y = 0, double width = 0, double height = 0, double size = 12, int align = txt::ALIGN_CENTER );
        virtual ~TextEdit() {};

        virtual void draw();
        virtual void update( double dt ) {};

        virtual bool mouseLeftDown() ;

        virtual bool keyPressed( unsigned int code );
        virtual bool keyReleased( unsigned int code ) {};
        virtual bool textEntered( unsigned int code );

        std::string getStringValue() const;

    private:

        sf::String m_value;
        int m_cursor;
        int m_align;
        bool m_allowEdit;
        double m_size;


};

#endif // TEXTEDIT_HPP
