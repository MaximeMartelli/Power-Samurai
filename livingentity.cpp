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

#include "livingentity.hpp"


LivingEntity::LivingEntity(RenderWindow *win, Image& image,const Vector2i& nbrOfAnim, Map *myMap)
:Entity(win,image,nbrOfAnim,myMap)
{
   timer1_ = new Clock();
   timer2_ = new Clock();
   timer3_ = new Clock();
}

LivingEntity::~LivingEntity()
{
   while (!spells.empty())
	{ 
		delete spells.back(); 
		spells.pop_back(); 
	}
	while (!appliedeffects.empty())
	{ 
		delete appliedeffects.back(); 
		appliedeffects.pop_back(); 
	}
   delete timer1_;
	delete timer2_;
	delete timer3_;
}

Clock * LivingEntity::getTimer(int i) const {
   switch (i)
	{
      case  1 :
         return timer1_;
         break;
      case  2 :
         return timer2_;
         break; 
      case  3 :
         return timer3_;
  	      break;
      default :
         return timer1_;
         break;
	}
}
void LivingEntity::setTimer(int i, Clock* t) {
   switch (i)
	{
      case  1 :
         timer1_ = t;
         break;
      case  2 :
         timer2_ = t;
         break; 
      case  3 :
         timer3_ = t;
  	      break;
      default :
         timer1_ = t;
         break;
	}
}

float LivingEntity::getSpellDelay(int i) const {
   switch (i)
	{
      case  1 :
         return spell_delay1_;
         break;
      case  2 :
         return spell_delay2_;
         break; 
      case  3 :
         return spell_delay3_;
  	      break;
      default :
         return spell_delay1_;
         break;
	}
}
void LivingEntity::setSpellDelay(int i, float sd) {
   switch (i)
	{
      case  1 :
         spell_delay1_ = sd;
         break;
      case  2 :
         spell_delay2_ = sd;
         break; 
      case  3 :
         spell_delay3_ = sd;
  	      break;
      default :
         spell_delay1_ = sd;
         break;
	}
}

Image* LivingEntity::getImgSpell(int i) const {
   switch (i)
	{
      case  1 :
         return Spell1_;
         break;
      case  2 :
         return Spell2_;
         break; 
      case  3 :
         return Spell3_;
  	      break;
      default :
         return Spell1_;
         break;
	}
}
void LivingEntity::setImgSpell(int i, Image* img) {
   switch (i)
	{
      case  1 : {
         Spell1_ = img;
         break;
      }
      case  2 : {
         Spell2_ = img;

         break; 
      }
      case  3 :
         Spell3_ = img;

  	      break;
      default :
         Spell1_ = img;
         break;
	}
}

int LivingEntity::getSRange(int i) const {
   switch (i)
	{
      case  1 :
         return range1_;
         break;
      case  2 :
         return range2_;
         break; 
      case  3 :
         return range3_;
  	      break;
      default :
         return range1_;
         break;
	}

}
void LivingEntity::setSRange(int i, int r) {
   switch (i)
	{
      case  1 :
         range1_ = r;
         break;
      case  2 :
         range2_ = r;
         break; 
      case  3 :
         range3_ = r;
  	      break;
      default :
         range1_ = r;
         break;
	}
}

float LivingEntity::getDmg(int i) const {
   switch (i)
	{
      case  1 :
         return dmg1_;
         break;
      case  2 :
         return dmg2_;
         break; 
      case  3 :
         return dmg3_;
  	      break;
      default :
         return dmg1_;
         break;
	}
}
void LivingEntity::setDmg(int i, float d) {
   switch (i)
	{
      case  1 :
         dmg1_ = d;
         break;
      case  2 :
         dmg2_ = d;
         break; 
      case  3 :
         dmg3_ = d;
  	      break;
      default :
         dmg1_ = d;
         break;
	}
}

Vector2i LivingEntity::getVSpell(int i) const { 
   switch (i)
	{
      case  1 :
         return v_spell1_;
         break;
      case  2 :
         return v_spell2_;
         break; 
      case  3 :
         return v_spell3_;
  	      break;
      default :
         return v_spell1_;
         break;
	}
}
void LivingEntity::setVSpell(int i, Vector2i v) {
   switch (i)
	{
      case  1 :
         v_spell1_ = v;
         break;
      case  2 :
         v_spell2_ = v;
         break; 
      case  3 :
         v_spell3_ = v;
  	      break;
      default :
         v_spell1_ = v;
         break;
	}
}

float LivingEntity::getSManaCost(int i) const {
   switch (i)
	{
      case  1 :
         return mana_cost1_;
         break;
      case  2 :
         return mana_cost2_;
         break; 
      case  3 :
         return mana_cost3_;
  	      break;
      default :
         return mana_cost1_;
         break;
	}
}

void LivingEntity::setSManaCost(int i, float mc) {
   switch (i)
	{
      case  1 :
         mana_cost1_ = mc;
         break;
      case  2 :
         mana_cost2_ = mc;
         break; 
      case  3 :
         mana_cost3_ = mc;
  	      break;
      default :
         mana_cost1_ = mc;
         break;
	}
}

String 
LivingEntity::getName() const
{
	return name_;
}

int 
LivingEntity::getLife() const
{
	return life_;
}

int 
LivingEntity::getMana() const
{
	return mana_;
}

void 
LivingEntity::setName(String name)
{
	name_ = name;
}

void 
LivingEntity::setLife(int life)
{
	life_ = life;
}

void 
LivingEntity::setMana(int mana)
{
	mana_ = mana;
}
//Pour les gains/pertes de mana, on vérifie que l'on est bien dans les bornes.
void 
LivingEntity::lifePenalty(int penalty)
{
	life_ -= penalty;

	if(life_ < ZERO)
	{
		life_ = ZERO;
	}
}

void 
LivingEntity::lifeGain(int gain)
{
 	life_ += gain;

	if(life_ > lifeMax_)
	{
		life_ = lifeMax_;
	}
}

void 
LivingEntity::manaPenalty(int penalty)
{
	mana_ -= penalty;

	if(mana_ < ZERO)
	{
		mana_ = ZERO;
	}
}

void 
LivingEntity::manaGain(int gain)
{
 	mana_ += gain;

	if(mana_ > manaMax_)
	{
		mana_ = manaMax_;
	}
}

bool 
LivingEntity::isAlive() const
{
	return (life_ > ZERO);
}

bool 
LivingEntity::haveMana() const
{
	return (mana_ > ZERO);
}

int  
LivingEntity::getLifeMax() const
{
	return lifeMax_;
}

int  
LivingEntity::getManaMax() const
{
	return manaMax_;
}

void  
LivingEntity::setLifeMax(int life)
{
	lifeMax_ = life;
}

void  
LivingEntity::setManaMax(int mana)
{
	manaMax_ = mana;
}


void 
LivingEntity::bonusLifeMax(int life)
{
	lifeMax_ += life;
}

void 
LivingEntity::bonusManaMax(int mana)
{
	manaMax_ += mana;
}



void LivingEntity::setAttackDamage(float ad) 
{
   attack_damage = ad;
}

float LivingEntity::getAttackDamage() 
{
   return attack_damage;
}
