#ifndef HORIZONTALSLIDER_HPP
#define HORIZONTALSLIDER_HPP

#include "Container.hpp"

class HorizontalSlider : public Container
{
	public:

		HorizontalSlider( std::string id = "", float x = 0, float y = 0, float width = 0, int lo = 0, int hi = 100, int step = 1 );
		virtual ~HorizontalSlider();

		virtual void draw();
		virtual void update( double dt ){};

        virtual bool mouseLeftDown();
        virtual bool mouseLeftUp();
        virtual void mouseMoved( int x, int y );
        virtual bool mouseWheelMoved( int delta );
        virtual bool keyPressed( unsigned int code ){};

        void setRange( int lo, int hi, int step = -1 );

		//void setValue( int val );
		//int getIntValue() const;

	private:

        int m_minVal;
        int m_maxVal;
        int m_step;
        int m_value;

};


#endif // HORIZONTALSLIDER_HPP

