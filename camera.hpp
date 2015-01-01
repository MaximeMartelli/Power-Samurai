#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "config.hpp"
#include "entity.hpp"

class Camera
{
	public :

	Camera(RenderWindow* win, Entity* entity);
	~Camera();
	
	void run();
	
	void setCameraXY(int x, int y);
	int * getCameraX() const;
	int * getCameraY() const;
	Vector2f * getPosition() const;

	Vector2f *position_;

	private:
	RenderWindow *win_;
	View view_;
	Entity *entityFocused_;    //Entité sur laquelle la caméra est centrée
	
	int * Camera_X;      //Taille de la caméra
	int * Camera_Y;
	
};

#endif
