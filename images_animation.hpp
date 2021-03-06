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

#ifndef IMAGES_ANIMATION_HPP
#define IMAGES_ANIMATION_HPP


#include "stdafx.hpp"


// Classe permettant de charger la majeure partie des ressources friandes en mémoire
class Images
{
public:

   Images();
   ~Images();
   
   
   //Monstres	
	Image *image_Armor1;
	Image *image_Devil1;
	Image *image_Dragon1;
	Image *image_Fantome1;
	Image *image_Fantome2;
	Image *image_Reaper1;
	Image *image_Squelette;
	Image *image_Troll;	
	Image *image_Bat;
	Image *image_Bee;
	Image *image_Blueslime;
	Image *image_Greendragon1;
	Image *image_Greenscorpion;
	Image *image_Greenslime;
	Image *image_Mouse1;
	Image *image_Naga;	
	Image *image_Reddragon1;
	Image *image_Redeye;
	Image *image_Redscorpion;
	
	// Sorts
	Image *image_Attack1;
	Image *image_Attack2;
	Image *image_Attack3;
	Image *image_Attack4;
	Image *image_Attack5;
	Image *image_Attack6;
	Image *image_Attack7;
	Image *image_Attack8;
	Image *image_Attack9;
	Image *image_Attack10;	
	Image *image_Fire3;
	Image *image_Gun1;
	Image *image_Gun2;
	Image *image_Heal2;
	Image *image_Heal3;
	Image *image_Heal4;
	Image *image_Heal5;
	Image *image_Light1;
	Image *image_Light2;
	Image *image_Light7;
	Image *image_Meteor;
	Image *image_Special2;
	Image *image_Special5;
	Image *image_Special10;
	Image *image_Special12;
	Image *image_Special14;
	Image *image_Special15;
	Image *image_Special17;
	Image *image_State1;
	Image *image_Sword5;
	Image *image_Sword10;
	Image *image_Wind1;
	Image *image_Wind3;
	
	// Effets
	Image *image_Death;
	Image *image_degats;
	Image *image_hp_item;
	Image *image_mana_item;
	Image *image_projectile;
private:

};
	
#endif
