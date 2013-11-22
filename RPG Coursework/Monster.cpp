#include "Monster.h"
#include "statePlay.h"

Monster::Monster(Player * player)
{
	this->player = player;
	textFont = NULL;

	Health = 0;
	Strength = 0;
	Speed = 0;

	xsize = 0.15f;
	ysize = 0.15f;
	xpos = 0.0f;
	ypos = 0.0f;

}

void Monster::SetXPos(float Xpos){
	xpos = Xpos;
}

void Monster::SetYPos(float Ypos){
	ypos = Ypos;
}

void Monster::SetHealth(int health){
	Health = health;
}

void Monster::SetStrength(int strength){
	Strength = strength;
}

void Monster::SetSpeed(int speed){
	Speed = speed;
}

float Monster::GetXPos(){
	return xpos;
}

float Monster::GetYPos(){
	return ypos;
}

float Monster::GetXSize(){
	return xsize;
}

float Monster::GetYSize(){
	return ysize;
}

Monster::~Monster(void)
{

}