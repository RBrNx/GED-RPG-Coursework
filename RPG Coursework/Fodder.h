#pragma once

#include "gameState.h"
#include "statePlay.h"
#include "Label.h"
#include "Monster.h"

class Fodder: public Monster
{
public:
	Fodder(Player *); //pass player into fodder for collision
	void Draw(SDL_Window *window);
	bool Update();
	~Fodder(void);

private:

	TTF_Font* textFont; //setup font
	Label * FodderText; //pointer for fodder label
	Player * player; //pointer to player object

};