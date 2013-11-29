#pragma once
#include "items.h"
class HealthPack : public Items
{
public:
	HealthPack(Player*);
	void Draw(SDL_Window *window);
	int Update();
	~HealthPack(void);

private:
	TTF_Font* textFont;
	Label * itemText;
	Player * player;
};

