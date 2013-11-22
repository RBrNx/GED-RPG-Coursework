#include "Raider.h"
#include "statePlay.h"

Raider::Raider(Player * player) : Monster(player)
{
	this->player = player;
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	raiderText = new Label();
	raiderText->textToTexture("Raider",textFont);

}

bool Raider::Update(){
	if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return true;
		} else { 
			return false; 
		}
	}

	return false;
}

void Raider::Draw(SDL_Window *window) 
{
    glBegin(GL_POLYGON);
	
		glColor3f(0.0,1.0,0.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	raiderText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize());
}


Raider::~Raider(void)
{
	delete raiderText;
}
