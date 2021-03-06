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

#include "greendragon.hpp"


GreenDragon::GreenDragon(RenderWindow *win, Image &image, Map *myMap, int ident, int range, Image* image1, Image* image2, Image* image3)
:Bot( win,
			image, 
			Vector2i(GREEN_DRAGON_X,GREEN_DRAGON_Y), 
			String("GreenDragon"),
			GREEN_DRAGON_LIFE,
			GREEN_DRAGON_MANA, 
			GREEN_DRAGON_POWER,
			myMap,
			GREEN_DRAGON_DMG,
			GREEN_DRAGON_ATK_DELAY,
			GREEN_DRAGON_SPEED,
			ident,
			range,
			GREEN_DRAGON_XP, image1, image2, image3
			)
{	      
         setSpellDelay(1, GREEN_DRAGON_DELAY1);
         setSpellDelay(2, GREEN_DRAGON_DELAY2);
         setSpellDelay(3, GREEN_DRAGON_DELAY3);
         setSRange(1, GREEN_DRAGON_RANGE1);
         setSRange(2, GREEN_DRAGON_RANGE2);
         setSRange(3, GREEN_DRAGON_RANGE3);
         setDmg(1, GREEN_DRAGON_DMG1);
         setDmg(2, GREEN_DRAGON_DMG2);
         setDmg(3, GREEN_DRAGON_DMG3);
         setVSpell(1, GREEN_DRAGON_V2I1);
         setVSpell(2, GREEN_DRAGON_V2I2);
         setVSpell(3, GREEN_DRAGON_V2I3);
         setImgSpell(1, image1);
         setImgSpell(2, image2);
         setImgSpell(3, image3);
         setSManaCost(1, GREEN_DRAGON_MANA_COST1);
         setSManaCost(2, GREEN_DRAGON_MANA_COST2);
         setSManaCost(3, GREEN_DRAGON_MANA_COST3);
}


GreenDragon::~GreenDragon()
{}


