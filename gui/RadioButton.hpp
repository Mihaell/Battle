#ifndef RADIOBUTTON_HPP
#define RADIOBUTTON_HPP

#include "Container.hpp"
#include "Label.hpp"

class RadioButton : public Container
{
	public:

		RadioButton( std::string id = "", std::string val = "", double x = 0, double y = 0 );
		virtual ~RadioButton(){};

        virtual void draw();
        virtual void update( double dt );

        virtual void mouseMoved( int x, int y );
        virtual bool mouseLeftDown();

        void setSelected( bool selected );

	private:

        bool m_selected;
        Label* m_label;

};


#endif // RADIOBUTTON_HPP

