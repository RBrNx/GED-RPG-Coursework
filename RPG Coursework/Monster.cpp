#include "Monster.h"
#include "statePlay.h"

Monster::Monster(Player * player)
{
	this->player = player;
	textFont = NULL;

	Health = 0; 
	Strength = 0;
	Speed = 0;
	ID = 0;
	dropPercentage = 0;

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

void Monster::SetID(int id){
	ID = id;
}

void Monster::SetMoneyDrop(int money){
	MoneyDrop = money;
}

void Monster::SetDropPercentage(int percentage){
	dropPercentage = percentage;
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

int Monster::GetID(){
	return ID;
}

int Monster::GetHealth(){
	return Health;
}

int Monster::GetStrength(){
	return Strength;
}

int Monster::GetSpeed(){
	return Speed;
}

int Monster::GetMoneyDrop(){
	return MoneyDrop;
}

int Monster::GetDropPercentage(){
	return dropPercentage;
}

void Monster::subtractDamage(int strength){
	Health -= strength;
}

Monster::~Monster(void)
{

}