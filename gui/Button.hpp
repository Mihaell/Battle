#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Container.hpp"

class Button : public Container
{
    public:

        Button( std::string id = "", std::string val = "", double x = 0, double y = 0, double width = 200, double height = 40, int align = txt::ALIGN_CENTER, double size = 12 );
        virtual ~Button() {};

        virtual bool mouseLeftDown();
        virtual bool mouseLeftUp();

        virtual void draw(sf::RenderWindow &window);
        virtual void update( double dt );

        void callCallback();

        void setValue( std::string val );
        std::string getValue() const;

        //bool isClicked();

        std::string getStringValue() const;

    protected:

        int m_align;
        double m_size;
        //bool m_clicked;

        double del;
        sf::String m_value;
        sf::Font m_font;
};

#endif // BUTTON_HPP
