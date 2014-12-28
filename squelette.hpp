#ifndef SQUELETTE_HPP
#define SQUELETTE_HPP

#include "bot.hpp"
#include "config.hpp"
#include "folowinganimation.hpp"

#define SQUELETTE_X 3
#define SQUELETTE_Y 4
#define SQUELETTE_LIFE 1000
#define SQUELETTE_MANA  500
#define SQUELETTE_POWER None
#define SQUELETTE_DMG 100
#define SQUELETTE_ATK_DELAY 5
#define SQUELETTE_XP 10
#define SQUELETTE_SPEED 1.5
#define SQUELETTE_RANGE1 1
#define SQUELETTE_RANGE2 3
#define SQUELETTE_RANGE3 -1
#define SQUELETTE_DELAY1 1
#define SQUELETTE_DELAY2 6
#define SQUELETTE_DELAY3 10
#define SQUELETTE_DMG1 50
#define SQUELETTE_DMG2 100
#define SQUELETTE_DMG3 200
#define SQUELETTE_V2I1 Vector2i(5,3)
#define SQUELETTE_V2I2 Vector2i(5,3)
#define SQUELETTE_V2I3 Vector2i(5,5)
#define SQUELETTE_MANA_COST1 0
#define SQUELETTE_MANA_COST2 0
#define SQUELETTE_MANA_COST3 0

class Squelette : public Bot
{
	public :

	Squelette(RenderWindow *win, Image &image, Map *myMap, int ident, int range);

	~Squelette();

	private:

};

#endif