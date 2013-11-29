#pragma once
#include "game.h"
#include "Player.h"

class Monster
{
public:
	Monster(Player*); //pass player into the monsters for collision
	virtual ~Monster();
	virtual void Draw(SDL_Window *window) = 0;
	virtual bool Update() = 0;

	float GetXPos();
	float GetYPos();
	float GetXSize();
	float GetYSize();
	int GetID();
	int GetHealth();
	int GetStrength();
	int GetSpeed();
	int GetMoneyDrop();

	void SetXPos(float Xpos);
	void SetYPos(float Ypos);
	void SetHealth(int health);
	void SetStrength(int strength);
	void SetSpeed(int speed);
	void SetID(int ID);
	void SetMoneyDrop(int money);

	void subtractDamage(int);
	
private:
	int Health;
	int Strength;
	int Speed;
	int ID; 
	int MoneyDrop;

	float xpos;
	float ypos;
	float xsize;
	float ysize;

	TTF_Font* textFont;
	Player * player;


};

