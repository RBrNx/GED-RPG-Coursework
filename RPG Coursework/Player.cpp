#include "Player.h"


Player::Player(void)
{
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	playerText = new Label();
	playerText->textToTexture("Player",textFont);

	Health = 12;
	Strength = 7;
	Speed = 12;

	xsize = 0.15f;
	ysize = 0.15f;
	xpos = 0.0f;
	ypos = 0.0f;

}

void Player::Update()
{

}

void Player::Draw(SDL_Window *window) 
{
    glBegin(GL_POLYGON);
	
		glColor3f(1.0,1.0,1.0);
      
		glVertex2f(xpos, ypos); 
		glVertex2f(xpos+ysize, ypos); 
		glVertex2f(xpos+ysize, ypos+ysize);
		glVertex2f(xpos, ypos+ysize); 
    
	glEnd();

	playerText->draw(xpos, ypos + ysize);
}

void Player::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_UP:
			case 'w': case 'W': 
				ypos += 0.05f;
				break;

			case SDLK_DOWN:
			case 's': case 'S':
				ypos -= 0.05f;
				break;

			case SDLK_LEFT:
			case 'a': case 'A': 
				xpos -= 0.05f;
				break;

			case SDLK_RIGHT:
			case 'd': case 'D':
				xpos += 0.05f;
				break;

			default:
				break;
		}
	}
}

float Player::GetXPos(){
	return xpos;
}

float Player::GetYPos(){
	return ypos;
}

float Player::GetXSize(){
	return xsize;
}

float Player::GetYSize(){
	return ysize;
}


Player::~Player(void)
{
	delete playerText;
}
