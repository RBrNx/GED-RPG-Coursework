#pragma once
#include "items.h"
class CombatPack : public Items
{
public:
	CombatPack(Player*);
	void Draw(SDL_Window *window);
	int Update();
	~CombatPack(void);

private:
	TTF_Font* textFont;
	Label * itemText;
	Player * player;
};