#pragma once
#include"Label.h"
#include"Player.h"
class Items
{
public:
	Items(Player*);
	virtual int Update() = 0;
	virtual void Draw(SDL_Window *window) = 0;
	void SetXPos(float Xpos);
	void SetYPos(float Ypos);

	float GetXPos();
	float GetYPos();
	float GetXSize();
	float GetYSize();
	~Items(void);

private:
	float xpos;
	float ypos;
	float xsize;
	float ysize;

	Player * player;
};

