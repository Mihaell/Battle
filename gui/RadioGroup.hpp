#ifndef RADIOGROUP_HPP
#define RADIOGROUP_HPP

#include "Container.hpp"
#include "RadioButton.hpp"

class RadioGroup : public Container
{
	public:
		RadioGroup( std::string id = "", double x = 0, double y = 0 );
		virtual ~RadioGroup();

        virtual void draw();
        virtual void update( double dt ){};

        virtual bool mouseLeftDown();

        std::string getStringValue() const;

	private:

        RadioButton* m_selectedChild;

};


#endif // RADIOGROUP_HPP

