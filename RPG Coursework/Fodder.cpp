#include "Fodder.h"
#include "statePlay.h"

Fodder::Fodder(Player * player) : Monster(player)
{
	this->player = player;
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	FodderText = new Label();
	FodderText->textToTexture("Fodder",textFont);

	SetHealth(12);
	SetStrength(7);
	SetSpeed(12);
	SetID(2);

}

bool Fodder::Update(){
	if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return true;
		} else { 
			return false; 
		}
	}

	return false;
}

void Fodder::Draw(SDL_Window *window) 
{
    glBegin(GL_POLYGON);
	
		glColor3f(0.0,1.0,0.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	FodderText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize());
}


Fodder::~Fodder(void)
{
	delete FodderText;
}



