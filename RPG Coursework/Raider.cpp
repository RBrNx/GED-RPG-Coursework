#include "Raider.h"
#include "statePlay.h"

Raider::Raider(Player * player) : Monster(player)
{
	this->player = player; //passes player to raider
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	raiderText = new Label();
	raiderText->textToTexture("Raider",textFont); //sets up label

	SetHealth(12); //inital stats
	SetStrength(7);
	SetSpeed(12);
	SetID(3);
	SetMoneyDrop(100);

}

bool Raider::Update(){
	if(player->GetXPos() <= this->GetXPos() + this->GetXSize() && player->GetXPos() + player->GetXSize() >= this->GetXPos()) {
		if(player->GetYPos() <= this->GetYPos() + this->GetYSize() && player->GetYPos() + player->GetYSize() >= this->GetYPos()){
			return true; //returns true if there is a collision
		} else { 
			return false; 
		}
	}

	return false;
}

void Raider::Draw(SDL_Window *window) 
{
    glBegin(GL_POLYGON); //draws raider
	
		glColor3f(1.0,0.0,0.0);
      
		glVertex2f(this->GetXPos(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos()); 
		glVertex2f(this->GetXPos() + this->GetXSize(), this->GetYPos() + this->GetYSize());
		glVertex2f(this->GetXPos(), this->GetYPos() + this->GetYSize()); 
    
	glEnd();

	raiderText->draw(this->GetXPos(), this->GetYPos() + this->GetYSize()); //draws label
}


Raider::~Raider(void)
{
	delete raiderText;
}
