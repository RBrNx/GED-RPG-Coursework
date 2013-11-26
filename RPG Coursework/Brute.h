#pragma once
#include "Monster.h"
#include "gameState.h"
#include "statePlay.h"
#include "Label.h"

class Brute : public Monster
{
public:
	Brute(Player *);
	void Draw(SDL_Window *window);
	bool Update();
	~Brute(void);

private:

	TTF_Font* textFont;
	Label * bruteText;
	Player * player;
};

