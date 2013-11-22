#pragma once
#include "Monster.h"

class Brute : public Monster
{
public:
	Brute(Player *);
	//void Draw(SDL_Window *window);
	//bool Update();
	~Brute(void);

	float xpos;
	float ypos;
	float xsize;
	float ysize;
};

