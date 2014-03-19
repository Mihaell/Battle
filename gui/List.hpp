#ifndef LIST_HPP
#define LIST_HPP

#include "../_inc_typ.hpp"
#include "Container.hpp"

class List : public Container
{
	public:
		List( std::string id = "", double x = 0, double y = 0, double width = 0, double height = 0 );
		virtual ~List();

        virtual void draw();
        virtual void update( double dt ){};

        //virtual void mouseMoved( int x, int y );

        virtual bool mouseWheelMoved( int delta ){};
        virtual bool mouseLeftDown();
        virtual bool mouseLeftUp();

        virtual void addItem( std::string id, std::string value ){};

        //std::string getStringValue() const;


	private:

        double m_off;
        int m_selected;

};


#endif // LIST_HPP

