#pragma once

#include "gameState.h"
#include "statePlay.h"
#include "Label.h"
#include "Monster.h"

class Raider: public Monster
{
public:
	Raider(Player *);
	void Draw(SDL_Window *window);
	bool Update();
	~Raider(void);

private:

	TTF_Font* textFont;
	Label * raiderText;
	Player * player;

};

