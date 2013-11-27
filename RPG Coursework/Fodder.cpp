#include "Fodder.h"
#include "statePlay.h"

Fodder::Fodder(Player * player) : Monster(player)
{
	this->player = player; //passes player to fodder
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	FodderText = new Label();
	FodderText->textToTexture("Fodder",textFont); //sets up label

	SetHealth(3);
	SetStrength(3);
	SetSpeed(7);
	SetID(2);

}

bool Fodder::Update(){
	if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return true; //returns true if there is a collision
		} else { 
			return false; 
		}
	}

	return false;
}

void Fodder::Draw(SDL_Window *window) 
{
    glBegin(GL_POLYGON); //draws fodder
	
		glColor3f(0.0,1.0,0.0); //green
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	FodderText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize()); // draws label
}


Fodder::~Fodder(void)
{
	delete FodderText;
}



