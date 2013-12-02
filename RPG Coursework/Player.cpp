#include "Player.h"


Player::Player(void)
{
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	playerText = new Label();
	playerText->textToTexture("Player",textFont); //sets up label


	Health = 10;
	MaxHealth = 10;
	Strength = 10; //sets up initial stats
	Speed = 10;
	Money = 0;

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
    glBegin(GL_POLYGON); //draws player
	
		glColor3f(1.0,1.0,1.0);
      
		glVertex2f(xpos, ypos); 
		glVertex2f(xpos+ysize, ypos); 
		glVertex2f(xpos+ysize, ypos+ysize);
		glVertex2f(xpos, ypos+ysize); 
    
	glEnd();

	playerText->draw(xpos, ypos + ysize); //draws label
}

void Player::subtractDamage(int strength){
	Health -= strength;
}

void Player::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_UP:
			case 'w': case 'W': //moves player on key press
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

int Player::GetHealth(){
	return Health;
}

int Player::GetStrength(){
	return Strength;
}

int Player::GetSpeed(){
	return Speed;
}

int Player::GetMoney(){
	return Money;
}

void Player::SetHealth(int health){
	Health = health;
}

void Player::HealPlayer(int recover){
	Health += recover;
}

void Player::IncreaseMaxHealth(){
	if(Health == MaxHealth){
		MaxHealth += 1;
		Health = MaxHealth;
	}else (Health = MaxHealth);
}

void Player::SetMoney(int money){
	Money += money;
}

void Player::increaseSpeed(int speed){
	Speed += speed;
}

void Player::increaseStrength(int strength){
	Strength += strength;
}

Player::~Player(void)
{
	delete playerText;
}
