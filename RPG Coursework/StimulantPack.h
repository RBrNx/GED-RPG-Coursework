#pragma once
#include "items.h"
class StimulantPack : public Items
{
public:
	StimulantPack(Player*);
	void Draw(SDL_Window *window);
	int Update();
	~StimulantPack(void);

private:
	TTF_Font* textFont;
	Label * itemText;
	Player * player;
};