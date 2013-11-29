#pragma once
#include "CombatPack.h"

CombatPack::CombatPack(Player * player) : Items(player){
	this->player = player;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	itemText = new Label();
	itemText->textToTexture("Combat Pack",textFont); //creates label
}

void CombatPack::Draw(SDL_Window *window){
	glBegin(GL_POLYGON); //draws combatpack
	
		glColor3f(0.0,0.0,1.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	itemText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize()); //draws label
}

int CombatPack::Update(){
		if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return 2; //returns true if there is a collision
		} else { 
			return 0; 
		}
	}

	return 0;
}

CombatPack::~CombatPack(void)
{
	delete itemText;
}
