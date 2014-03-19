#ifndef UNIT_H
#define UNIT_H

#include <SFML/Graphics.hpp>
#include <string>

class Unit:public sf::Sprite
{
    public:
        Unit(std::string tex);
        ~Unit();

    protected:
    private:

        int HP;
        int DAMAGE;
        sf::Texture texture;
};


#endif // UNIT_H

