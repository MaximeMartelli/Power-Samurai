#include <sstream>
#include <SFML/Graphics.hpp>
#include "statusbar.hpp"



StatusBar::StatusBar(RenderWindow *win, Player *player, Camera *camera)
	: player_(player) 
	,win_(win)	
	,camera_(camera)
{
	StatusBar_  = new Image();
	StatusBar_->LoadFromFile("images/StatusBar/StatusBar.png");
	
	Life_ = new Image();
	Life_->LoadFromFile("images/StatusBar/HP_Bar.png");
	
	Mana_  = new Image();
	Mana_->LoadFromFile("images/StatusBar/Mana_bar.png");

   statuLife_.SetImage(*Life_);
   statuMana_.SetImage(*Mana_);
   statusBar_.SetImage(*StatusBar_);

   /*String *NamePlayer_;
	String *Level_;
	String *HP_Pot_Nb_;
	String *MANA_Pot_Nb_;*/
	
	Perso_ = new Font();
   if (!Perso_->LoadFromFile("Fonts/perso.ttf"))
	      cout << "erreur" << endl;
	
	NamePlayer_ = new String();
	*NamePlayer_ = player_->getName();
	NamePlayer_->SetSize(16);
	NamePlayer_->SetStyle(11);
	NamePlayer_->SetColor(Color(0, 0, 0));
	NamePlayer_->SetFont(*Perso_);

   Level_ = new String();
   Level_->SetText("Lvl : ");
   Level_->SetSize(16);
	Level_->SetStyle(11);
	Level_->SetColor(Color(0, 0, 0));
	Level_->SetFont(*Perso_);
		 
		 
	HP_Pot_Nb_ = new String();
	HP_Pot_Nb_->SetText(to_string(player_->getNbHP()));	 
	HP_Pot_Nb_->SetSize(20);
	HP_Pot_Nb_->SetStyle(11);
	HP_Pot_Nb_->SetColor(Color(0, 0, 0));
	HP_Pot_Nb_->SetFont(Font::GetDefaultFont());
	//NamePlayer_->SetPosition(10,win_->GetHeight()-23); 
   //string s = std::to_string(42);
   
   MANA_Pot_Nb_ = new String();
	MANA_Pot_Nb_->SetText(to_string(player_->getNbMANA ()));	 
	MANA_Pot_Nb_->SetSize(20);
	MANA_Pot_Nb_->SetStyle(11);
	MANA_Pot_Nb_->SetColor(Color(0, 0, 0));
	MANA_Pot_Nb_->SetFont(Font::GetDefaultFont());

	position_ = camera->getPosition();

	/*statuLife_ = Shape::Rectangle(0,
										   0,
											118,
											12,
											LIFE_COLOR,
											LIFE_BORDURE,
											LIFE_BORDURE_COLOR); 

	statuMana_ = Shape::Rectangle(0,
										   0,
											118,
											12,
											MANA_COLOR,
											MANA_BORDURE,
											MANA_BORDURE_COLOR); 

	statuLifeRed_ = Shape::Rectangle(0,
										  		0,
												118,
												12,
												RED_COLOR,
												LIFE_BORDURE,
												LIFE_BORDURE_COLOR);

	statuManaRed_ = Shape::Rectangle(0,
										   	0,
												118,
												12,
												RED_COLOR,
												MANA_BORDURE,
												MANA_BORDURE_COLOR);*/
}


StatusBar::~StatusBar()
{
	
}

void 
StatusBar::update()
{
	//statuLife_.SetScaleX(0.5);
   
   NamePlayer_->SetPosition(PLAYER_POSITION_X, PLAYER_POSITION_Y);
   Level_->SetPosition(LVL_POSITION_X, LVL_POSITION_Y);
   
	HP_Pot_Nb_->SetText(to_string(player_->getNbHP()));	 
   HP_Pot_Nb_->SetPosition(NBHP_POSITION_X, NBHP_POSITION_Y);
   
   MANA_Pot_Nb_->SetText(to_string(player_->getNbMANA()));	 
   MANA_Pot_Nb_->SetPosition(NBMANA_POSITION_X, NBMANA_POSITION_Y);
	//myText_->SetPosition  (TEXT_POSITION_X, TEXT_POSITION_Y);
	statusBar_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);
	statuLife_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);
	statuMana_.SetPosition(SPRITE_POSITION_X, SPRITE_POSITION_Y);

	/*statuLife_.SetPosition(LIFE_POSITION_X, LIFE_POSITION_Y);
	statuMana_.SetPosition(MANA_POSITION_X, MANA_POSITION_Y);
	statuLifeRed_.SetPosition(LIFE_POSITION_X, LIFE_POSITION_Y);
	statuManaRed_.SetPosition(MANA_POSITION_X, MANA_POSITION_Y);*/
}

void
StatusBar::display ()
{
   
   

	update();
	playLifeEffect(getPlayer());
	playManaEffect(getPlayer());
	win_->Draw(statusBar_);
	win_->Draw(*NamePlayer_);
	win_->Draw(*Level_);
	win_->Draw(*HP_Pot_Nb_);
	win_->Draw(*MANA_Pot_Nb_);
	win_->Draw(statuLife_);
	win_->Draw(statuMana_);
	
}


void StatusBar::playLifeEffect(Player *player) {
   statuLife_.SetSubRect( IntRect(0, 0, 100 + (int) 122 * ( (float) player->getLife() / (float) player->getLifeMax() ), 600));
}


void StatusBar::playManaEffect(Player *player) {
   statuMana_.SetSubRect( IntRect(0, 0, 100 + (int) 122 * ( (float) player->getMana() / (float) player->getManaMax() ), 600));	
}

void 
StatusBar::setPosition(Vector2f *position)
{
	position_->x = position->x;
	position_->y = position->y; 
}

void 
StatusBar::setPlayer(Player *player)
{
	player_ = player;
}

void 
StatusBar::setWindow(RenderWindow *win)
{
	win_ = win;
}


void 
StatusBar::setSprite(Sprite sprite)
{
	statusBar_ = sprite;
}


void 
StatusBar::setImage(Image *image)
{
	StatusBar_ = image;
}

Vector2f* 
StatusBar::getPosition() const
{
	return position_;
}


Player*
StatusBar::getPlayer() const
{
	return player_;
}


RenderWindow* 
StatusBar::getWindow() const
{
	return win_;
}


Sprite 
StatusBar::getSprite() const
{
	return statusBar_;
}


Image*  
StatusBar::getImage()  const
{
	return StatusBar_;
}


