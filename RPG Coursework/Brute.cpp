#include "Brute.h"

Brute::Brute(Player * player) : Monster(player)
{
	this->player = player; //passes player to brute
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	bruteText = new Label();
	bruteText->textToTexture("Brute",textFont); //creates label

	SetHealth(12);
	SetStrength(8);
	SetSpeed(6);
	SetID(1);
}

bool Brute::Update(){
	if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return true; //returns true if there is a collision
		} else { 
			return false; 
		}
	}

	return false;
}

void Brute::Draw(SDL_Window *window) 
{
    glBegin(GL_POLYGON); //draws brute
	
		glColor3f(1.0,1.0,0.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	bruteText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize()); //draws label
}


Brute::~Brute(void)
{
	delete bruteText;
}
