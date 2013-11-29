#include "Items.h"


Items::Items(Player* player)
{
	this->player = player;
	xpos = 0;
	ypos = 0;
	xsize = 0.1f;
	ysize = 0.1f;
}

float Items::GetXPos(){
	return xpos;
}

float Items::GetYPos(){
	return ypos;
}

float Items::GetXSize(){
	return xsize;
}

float Items::GetYSize(){
	return ysize;
}

void Items::SetXPos(float XPos){
	xpos = XPos;
}

void Items::SetYPos(float YPos){
	ypos = YPos;
}

Items::~Items(void)
{
}
