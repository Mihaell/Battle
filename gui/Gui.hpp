#ifndef GUI_HPP
#define GUI_HPP

#include "../_inc_typ.hpp"

#include "Container.hpp"
#include "Button.hpp"
#include "TextEdit.hpp"
#include "Label.hpp"
#include "RadioButton.hpp"
#include "RadioGroup.hpp"
#include "List.hpp"
#include "HorizontalSlider.hpp"
#include "ScrollableContainer.hpp"

#include "WindowMenu.hpp"

class Gui
{
    public:

        Gui();
        ~Gui();

        void draw(sf::RenderWindow &window);
        void update( double dt );
        void handleEvents( const sf::Event& event );

        ContainerPt addChild( ContainerPt );

        void registerChild( const std::string& id, ContainerPt child );

        ContainerPt& getChild( const std::string& id );

    private:

        ContainerPt m_root;

        std::map< std::string, ContainerPt > m_childs;

};

#endif
