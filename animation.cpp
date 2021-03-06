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

#include "animation.hpp"

Animation::Animation(RenderWindow *win, Image &image, const Vector2i& nbrOfAnim)
: win_(win)
, paused_(false)
, myImage_(image)
, numberOfAnim_(nbrOfAnim)
, animationFps_(DEFAULT_ANIM_FPS)
, anim_(1,0) 
{
   //Timer_animation = new Clock();
	mySprite_ = new Sprite();
	mySprite_->SetImage(image); 
	
	myAnimationSoundB_ = new SoundBuffer();
	myAnimationSound_ = new Sound();
	
	

	sizeImage_.x    = image.GetWidth(); 
	sizeImage_.y    = image.GetHeight(); 
	sizeSprite_.x   = image.GetWidth()  / nbrOfAnim.x;
	sizeSprite_.y   = image.GetHeight() / nbrOfAnim.y;

	setDefaultSprite();
}

Animation::~Animation()
{
    myAnimationSound_->Stop();
	 delete mySprite_;
	 delete myAnimationSound_;
	 delete myAnimationSoundB_;
}
 
Sprite* 
Animation::getSprite() const
{
	return mySprite_;
}

void
Animation::setAnimation(int i)
{
	int x ,y ;
 
	x = i % numberOfAnim_.x;
	y = i / numberOfAnim_.y;

	setAnimationX(x);
	setAnimationY(y);
	updateSprite();
}

void Animation::setAnimationWidth (int x) {
   sizeSprite_.x = x;
}
void Animation::setAnimationHeight (int y) {
   sizeSprite_.y = y;
}

void 
Animation::setImage(const string imageName)
{
	myImage_.LoadFromFile(imageName);
}


int  
Animation::getWidth () const
{
	return sizeImage_.x ;
}

int  
Animation::getHeight() const
{
	return sizeImage_.y;
}

int  
Animation::getAnimationWidth () const
{
	return sizeSprite_.x;
}

int  
Animation::getAnimationHeight() const
{
	return sizeSprite_.y;
}

Vector2f 
Animation::getCenter() const
{
	Vector2f new_position , position = getPosition();
	
	new_position.x = position.x + getAnimationWidth()  / 2; 
	new_position.y = position.y + getAnimationHeight() / 2;
	
	return new_position;
}

void 
Animation::setPosition(Vector2f position)
{
	mySprite_->SetPosition(position);
}

void 
Animation::setCenter(Vector2f position)
{
	Vector2f new_position;
	new_position.x = position.x - getAnimationWidth() / 2; 
	new_position.y = position.y - getAnimationHeight() / 2;
	
	mySprite_->SetPosition(new_position);
}


Vector2f 
Animation::getPosition() const
{
	return mySprite_->GetPosition();
}


void 
Animation::updateSprite()
{
	const int &x1 = anim_.x * sizeSprite_.x;
	const int &y1 = anim_.y * sizeSprite_.y;
	const int &x2 = x1 + sizeSprite_.x;
	const int &y2 = y1 + sizeSprite_.y;

	mySprite_->SetSubRect(IntRect(x1,y1,x2,y2));
}

void  
Animation::animationUp()
{
	if((anim_.y * sizeSprite_.y) > 0 )
		anim_.y--;
	else 
		anim_.y = (sizeImage_.y / sizeSprite_.y) - 1;
}

void  
Animation::animationDown()
{
	if( (anim_.y * sizeSprite_.y) < sizeImage_.y)
		anim_.y++;
	else 
		anim_.y = 0;
}

void  
Animation::animationLeft()
{
	if((anim_.x * sizeSprite_.x) > 0 )
		anim_.x--;
	else 
		anim_.x = (sizeImage_.x / sizeSprite_.x) - 1;
}

void  
Animation::animationRight()
{
	if((anim_.x * sizeSprite_.x) < sizeImage_.x - sizeSprite_.x)
		anim_.x++;
	else 
		anim_.x = 0;
}

void 
Animation::setAnimationX(int x)
{
	anim_.x = x;
}

void 
Animation::setAnimationY(int y)
{
	anim_.y = y;
}

int
Animation::getAnimationX() const
{
 	return anim_.x;
}

int 
Animation::getAnimationY() const
{
	return anim_.y;
}

void 
Animation::play()
{  
	paused_ = true;
}

void 
Animation::pause()
{
	paused_ = false;
}

bool
Animation::isPlaying() const
{
	return paused_;
}

void
Animation::SetAnimFps(int &fps)
{
	animationFps_ = fps;
}

int 
Animation::getAnimFps() const
{
	return animationFps_;
}

void 
Animation::draw()
{
   if (mySprite_ != NULL)
		win_->Draw(*mySprite_);
	else
	   cout << "erreur pointeur sur null " << endl ;
}

void 
Animation::setDefaultSprite()
{
	mySprite_->SetSubRect(IntRect(A_SPRITE_BEGIN_X,
											A_SPRITE_BEGIN_Y,		
											A_SPRITE_END_X,
											A_SPRITE_END_Y));
}


Sound * Animation::getSound() const 
{
   return myAnimationSound_;
}

void Animation::setSoundB(string s) 
{
	if (!myAnimationSoundB_->LoadFromFile(s))
		cout << "erreur " << endl ;

   myAnimationSound_->SetBuffer(*myAnimationSoundB_);

}

