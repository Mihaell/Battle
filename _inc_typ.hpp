#ifndef _INC_TYP_HPP
#define _INC_TYP_HPP

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>

#include "customStructs.hpp"

const double pi = acos( -1.0 );
const double piOver180 = pi / 180.0;

typedef sf::Vector2<double> Vec2f;

class App;
class StateManager;
class AssetManager;
class IState;

class Gui;
class Container;
class Button;
class TextEdit;


typedef App* AppPt;
typedef StateManager* StateManagerPt;
typedef AssetManager* AssetManagerPt;
typedef IState* IStatePt;

typedef Gui* GuiPt;
typedef Container* ContainerPt;
typedef Button* ButtonPt;
typedef TextEdit* TextEditPt;

#endif // _INC_TYP_HPP
