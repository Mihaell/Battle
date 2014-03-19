#include "unit.h"
#include <cstdio>

Unit::Unit(std::string tex)
{
    texture.loadFromFile( tex );
    setTexture( texture );
}

Unit::~Unit()
{

}
