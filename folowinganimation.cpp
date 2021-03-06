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

#include "folowinganimation.hpp"


FolowingAnimation::FolowingAnimation(RenderWindow *win, Image& image, 
												 const Vector2i nbrOfAnim, Entity *entity)
	: AnimationEffect(win,image,nbrOfAnim)
	, entity_(entity)
{}

FolowingAnimation::
~FolowingAnimation() {}


// Gère le déroulement de l'animation, et fait bien en sorte que celle ci suive l'entité passée en pointeur.
void 
FolowingAnimation::run() 
{
	if(isPlaying())
	{
		setCenter( (entity_->getCenter()) );
		if(getAnim() < getNmbEffect())
		{
			setAnimation( incrementationAnim() );
			draw();
		}
		else
		{
			setAnim(-1);
		}	
		if(isPlaying() && (getAnim() == -1))
			stop();			
	}
}

// Permet de boucler l'animation
void 
FolowingAnimation::loop() 
{
	if(isPlaying())
	{
		setCenter(entity_->getCenter());
		if(getAnim() < getNmbEffect())
		{
			setAnimation( incrementationAnim() );
			draw();
		}
		else
		{
			setAnim(-1);
		}				
	}
}
