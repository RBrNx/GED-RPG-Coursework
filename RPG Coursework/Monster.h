#pragma once
#include "game.h"
#include "Player.h"

class Monster
{
public:
	Monster(Player*);
	virtual ~Monster();
	virtual void Draw(SDL_Window *window) = 0;
	virtual bool Update() = 0;

	float GetXPos();
	float GetYPos();
	float GetXSize();
	float GetYSize();

	void SetXPos(float Xpos);
	void SetYPos(float Ypos);
	void SetHealth(int health);
	void SetStrength(int strength);
	void SetSpeed(int speed);
	
private:
	int Health;
	int Strength;
	int Speed;

	float xpos;
	float ypos;
	float xsize;
	float ysize;

	TTF_Font* textFont;
	Player * player;


};

