#pragma once

#include "gameState.h"
#include "Label.h"

class Player
{
public:
	Player(void);
	void Draw(SDL_Window *window);
	void Update();
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	float GetXPos();
	float GetYPos();
	float GetXSize();
	float GetYSize();
	int GetHealth();
	int GetStrength();
	int GetSpeed();
	int GetMoney();
	void increaseSpeed(int);
	void increaseStrength(int);
	void HealPlayer(int);
	void subtractDamage(int);
	void IncreaseMaxHealth();

	void SetHealth(int);
	void SetMoney(int);
	~Player(void);

private:
	int Health;
	int Strength;
	int Speed;
	int Money;
	int MaxHealth;

	float xpos;
	float ypos;
	float xsize;
	float ysize;

	TTF_Font* textFont;
	Label * playerText;

};
