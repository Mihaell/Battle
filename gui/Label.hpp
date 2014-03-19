#ifndef LABEL_HPP
#define LABEL_HPP

#include "Container.hpp"

class Label : public Container
{
	public:

		Label( std::string id = "", std::string val = "", double x = 0, double y = 0, double width = 0, int align = txt::ALIGN_LEFT, double size = 12 );
		virtual ~Label();

		virtual void draw();
		virtual void update( double dt ) {};

        virtual void setValue( std::string val );

		std::string getStringValue() const;

	private:

        sf::String m_value;
        int m_align;
        double m_size;


};


#endif // LABEL_HPP

