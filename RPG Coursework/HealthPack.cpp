#pragma once
#include "HealthPack.h"

HealthPack::HealthPack(Player * player) : Items(player){
	this->player = player;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	itemText = new Label();
	itemText->textToTexture("Health",textFont); //creates label
}

void HealthPack::Draw(SDL_Window *window){
	glBegin(GL_POLYGON); //draws healthpack
	
		glColor3f(1.0,0.0,0.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	itemText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize()); //draws label
}

int HealthPack::Update(){
		if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return 1; //returns true if there is a collision
		} else { 
			return 0; 
		}
	}

	return 0;
}

HealthPack::~HealthPack(void)
{
	delete itemText;
}
