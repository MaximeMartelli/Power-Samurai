#ifndef STATUSBAR_HPP
#define STATUSBAR_HPP

#include "stdafx.hpp"
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "config.hpp"
#include "camera.hpp"

#define PLAYER_POSITION_X position_->x - 330
#define PLAYER_POSITION_Y position_->y + 193

#define LVL_POSITION_X position_->x - 297
#define LVL_POSITION_Y position_->y + 250

#define NBHP_POSITION_X position_->x + 284
#define NBHP_POSITION_Y position_->y + 240

#define NBMANA_POSITION_X position_->x + 345
#define NBMANA_POSITION_Y position_->y + 240

#define SPRITE_POSITION_X position_->x - 400
#define SPRITE_POSITION_Y position_->y - 300

#define LIFE_POSITION_X position_->x - 307
#define LIFE_POSITION_Y position_->y + 214

#define MANA_POSITION_X position_->x - 307
#define MANA_POSITION_Y position_->y + 234

#define LIFE_X1 0
#define LIFE_Y1 0
#define LIFE_X2 118
#define LIFE_Y2 12
#define LIFE_COLOR Color(0,255,0,255)
#define LIFE_BORDURE 3
#define LIFE_BORDURE_COLOR Color(0,204,102,255)

#define MANA_X1 0
#define MANA_Y1 0
#define MANA_X2 118
#define MANA_Y2 12
#define MANA_COLOR Color(0,0,255,255)
#define MANA_BORDURE 3
#define MANA_BORDURE_COLOR Color(0,204,102,255)

#define RED_COLOR Color(255,0,0,255)

class StatusBar
{
public:

	StatusBar(RenderWindow *win, Player *player, Camera *camera);
	~StatusBar();  

	void display () ;
	void playLifeEffect(Player *player);
	void playManaEffect(Player *player);

	void update();

	void setPlayer(Player *player);
	void setWindow(RenderWindow *win);
	void setSprite(Sprite sprite);
	void setImage(Image *image);
	void setPosition(Vector2f *position);

	Player*   getPlayer() const;
	RenderWindow* getWindow() const;
	Sprite   getSprite()   const;
	Image*    getImage()    const;
	Vector2f* getPosition() const;

private:
   Player *player_;
	RenderWindow *win_;

	String *NamePlayer_;
	String *Level_;
	String *HP_Pot_Nb_;
	String *MANA_Pot_Nb_;
	
	
	Camera *camera_;
	Vector2f *position_;

	Sprite statuLife_;
	Sprite statuMana_;
	Sprite statusBar_;
	
	Image *Life_;
	Image *Mana_;
	Image *StatusBar_;
	
	Font *Perso_;
	};	

#endif 
