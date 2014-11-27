#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "entity.hpp"
#include "config.hpp"

class Player : public Entity
{
	public :
	
	Player(RenderWindow *win, Image& image, Vector2i& nbrOfAnim, String& name, int life, int mana, enum power power);
	~Player();

	void move(Key::Code keyPressed);

	String getName() const;
	int getLife() const;
	int getMana() const;

	void setName(String name);
	void setLife(int life);
	void setMana(int mana);

	void update();

	private:
	
	String &name_;
	int    life_;
	int    mana_;
	enum power power_;
};

#endif
