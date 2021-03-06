/*******************************************************************/
/*=================================================================*/
/************ -- PROJET : POWER SAMURAI 2D RPG -- ******************/
/*=================================================================*/
/*        [EI-SE4] Polytech Paris UPMC (2014-2015) (C++)           */
/*=================================================================*/
/*                       # Devloppeur #                            */
/*                       ==============                            */
/*                - lounes.achab@etu.upmc.fr                       */
/*               - maxime.martelli@etu.upmc.fr                     */
/*             - clement.maciejewski@etu.upmc.fr                   */
/*=================================================================*/
/*******************************************************************/

#include "greendragon1.hpp"


Greendragon1::Greendragon1(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(GREENDRAGON1_X,GREENDRAGON1_Y), 
			String("Greendragon1"),
			GREENDRAGON1_LIFE,
			GREENDRAGON1_MANA, 
			GREENDRAGON1_POWER,
			myMap,
			GREENDRAGON1_DMG,
			GREENDRAGON1_ATK_DELAY,
			GREENDRAGON1_SPEED,
			ident,
			range,
			GREENDRAGON1_XP, image1, image2, image3
			)
{	      setSpellDelay(1, GREENDRAGON1_DELAY1);
         setSpellDelay(2, GREENDRAGON1_DELAY2);
         setSpellDelay(3, GREENDRAGON1_DELAY3);
         setSRange(1, GREENDRAGON1_RANGE1);
         setSRange(2, GREENDRAGON1_RANGE2);
         setSRange(3, GREENDRAGON1_RANGE3);
         setDmg(1, GREENDRAGON1_DMG1);
         setDmg(2, GREENDRAGON1_DMG2);
         setDmg(3, GREENDRAGON1_DMG3);
         setVSpell(1, GREENDRAGON1_V2I1);
         setVSpell(2, GREENDRAGON1_V2I2);
         setVSpell(3, GREENDRAGON1_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, GREENDRAGON1_MANA_COST1);
         setSManaCost(2, GREENDRAGON1_MANA_COST2);
         setSManaCost(3, GREENDRAGON1_MANA_COST3);
}


Greendragon1::~Greendragon1()
{}


