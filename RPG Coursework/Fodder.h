#pragma once

#include "gameState.h"
#include "statePlay.h"
#include "Label.h"
#include "Monster.h"

class Fodder: public Monster
{
public:
	Fodder(Player *);
	void Draw(SDL_Window *window);
	bool Update();
	~Fodder(void);

private:

	TTF_Font* textFont;
	Label * FodderText;
	Player * player;

};