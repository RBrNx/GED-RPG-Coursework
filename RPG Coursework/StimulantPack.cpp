#pragma once
#include "StimulantPack.h"

StimulantPack::StimulantPack(Player * player) : Items(player){
	this->player = player;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	itemText = new Label();
	itemText->textToTexture("Stimulant",textFont); //creates label
}

void StimulantPack::Draw(SDL_Window *window){
	glBegin(GL_POLYGON); //draws combatpack
	
		glColor3f(0.0,1.0,0.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	itemText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize()); //draws label
}

int StimulantPack::Update(){
		if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return 3; //returns true if there is a collision
		} else { 
			return 0; 
		}
	}

	return 0;
}

StimulantPack::~StimulantPack(void)
{
	delete itemText;
}
