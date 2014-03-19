#ifndef WINDOWMENU_HPP
#define WINDOWMENU_HPP

#include "Container.hpp"

class WindowMenu : public Container
{
	public:
		WindowMenu( std::string id = "", double width = 0, double height = 0 );
		virtual ~WindowMenu(){};

        virtual void draw();
        virtual void update( double dt ){};

	private:

};


#endif // WINDOWMENU_HPP

