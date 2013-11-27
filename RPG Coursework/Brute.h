#pragma once
#include "Monster.h"
#include "gameState.h"
#include "statePlay.h"
#include "Label.h"

class Brute : public Monster
{
public:
	Brute(Player *); //pass player into brute for collision
	void Draw(SDL_Window *window);
	bool Update();
	~Brute(void);

private:

	TTF_Font* textFont; //setup font
	Label * bruteText; //pointer to brute label
	Player * player; //pointer to player object
};

