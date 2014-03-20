#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include "board.h"
#include "effects/effectManager.h"


class Game
{
    public:
        Game();
        ~Game();

        void draw( sf::RenderWindow &window );
        void update( double k );
        void handleEvent( sf::Event &event );

        static EffectManager* effManager;

    protected:
    private:

        Board* field;

};


#endif // GAME_H

