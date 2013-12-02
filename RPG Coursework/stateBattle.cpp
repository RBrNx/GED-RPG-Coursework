#include "game.h"
#include "stateBattle.h"
#include "gameOverState.h"
#include "Label.h"
#include <sstream>
#include <cstdlib>

#define RAND_CODE (float(rand())/float(RAND_MAX))

StateBattle::StateBattle() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font
		
	playerText = new Label(); //set up labels
	enemyText = new Label();
	battleText = new Label();

	itemDrop = false;

	battleText->textToTexture("Let Battle Commence!",textFont);
	playerText->textToTexture("Player",textFont);
}

void StateBattle::setupCharacters(Monster * monster, Player* player) {
	this->player = player; //passes player into the battle state so stats can be checked
	this->monster = monster;

	if(monster->GetID() == 1){
	enemyText->textToTexture("Brute",textFont);
	}else if (monster->GetID() == 2){
		enemyText->textToTexture("Fodder",textFont);
	}else if (monster->GetID() == 3){
		enemyText->textToTexture("Raider",textFont);
	}
}

void StateBattle::Update(Game &context)
{
	if (monsterDead == true) {
		context.setState(gameOver);
	}
	else if(playerDead == true) {
		context.setState(gameOver);
	}
}

void StateBattle::Draw(SDL_Window *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	glClearColor(0.0, 0.0, 0.0, 0.0); 

	 glBegin(GL_POLYGON); //draws player in bottom left
		glColor3f(1.0,1.0,1.0);
		glVertex2f(-1.0f, -1.0f); 
		glVertex2f(-1.0f+0.5f, -1.0f); 
		glVertex2f(-1.0f+0.5f, -1.0f+0.5f);
		glVertex2f(-1.0f, -1.0f+0.5f); 
	glEnd();

	playerText->draw(-0.8f,-0.5f); //draws label

	glBegin(GL_POLYGON); //draws monster in top right
	if(monster->GetID() == 1){
		glColor3f(1.0,1.0,0.0);
	}else if (monster->GetID() == 2){
		glColor3f(0.0,1.0,0.0);
	}else if (monster->GetID() == 3){
		glColor3f(1.0,0.0,0.0);
	}
		glVertex2f(0.5f, 0.5f); 
		glVertex2f(0.5f+0.5f, 0.5f); 
		glVertex2f(0.5f+0.5f, 0.5f+0.5);
		glVertex2f(0.5f, 0.5f+0.5f); 
	glEnd();

	enemyText->draw(0.7f, 0.45f); //draws label

	battleText->draw(-0.9f, 0.8f); //draws label

	std::stringstream strStream;
	std::stringstream strStream2;
	std::stringstream strStream3;

	//puts the players health, strength and speed into a stringstream and displays it on screen
	strStream << "Health: " << player->GetHealth() << std::endl;
	Label playerStream;
	playerStream.textToTexture(strStream.str().c_str(), textFont);
	playerStream.draw(-0.4f,-0.6f);

	strStream2 << "Strength: " << player->GetStrength() << std::endl;
	Label playerStream2;
	playerStream2.textToTexture(strStream2.str().c_str(), textFont);
	playerStream2.draw(-0.4f,-0.7f);

	strStream3 << "Speed: " << player->GetSpeed() << std::endl;
	Label playerStream3;
	playerStream3.textToTexture(strStream3.str().c_str(), textFont);
	playerStream3.draw(-0.4f,-0.8f);

	std::stringstream strStream4;
	std::stringstream strStream5;
	std::stringstream strStream6;

	//puts the monsters health, strength and speed into a stringstream and displays it onscreen
	strStream4 << "Health: " << monster->GetHealth() << std::endl;
	Label playerStream4;
	playerStream4.textToTexture(strStream4.str().c_str(), textFont);
	playerStream4.draw(0.2f,0.8f);

	strStream5 << "Strength: " << monster->GetStrength() << std::endl;
	Label playerStream5;
	playerStream5.textToTexture(strStream5.str().c_str(), textFont);
	playerStream5.draw(0.2f,0.7f);

	strStream6 << "Speed: " << monster->GetSpeed() << std::endl;
	Label playerStream6;
	playerStream6.textToTexture(strStream6.str().c_str(), textFont);
	playerStream6.draw(0.2f,0.6f);
	
	SDL_GL_SwapWindow(window); // swap buffers
}

void StateBattle::CommenceBattle() {
		do{
			healthAtStart = player->GetHealth();
		//if player is faster than monster, player hits first
		if(player->GetSpeed() > monster->GetSpeed()){
			std::cout << "Player hits first" << std::endl;
			monster->subtractDamage(RAND_CODE * (player->GetStrength() - (2) + (2)));
			if(monster->GetHealth() > 0) {
				player->subtractDamage(RAND_CODE * (monster->GetStrength() - (2) + (2)));
			}
		}

		//if player is slower than monster, monster hits first
		if(player->GetSpeed() < monster->GetSpeed()){
			std::cout << "Monster hits first for " << std::endl;
			std::cout << player->GetHealth() << std::endl;
			player->subtractDamage(RAND_CODE * (monster->GetStrength() - (2) + (2)));
			if(player->GetHealth() > 0) {
				monster->subtractDamage(RAND_CODE * (player->GetStrength() - (2) + (2)));
			}
		}
		//if speeds are equal, do a random pick. If random pick = 0, monster hits first. If random pick = 1, player hits first
		if(player->GetSpeed() == monster->GetSpeed()){
		 int randomPick = (float(rand())/float(RAND_MAX)) * (1.0f - 0.0f) + (0.0f);
		 if(randomPick == 0){
			 player->subtractDamage(RAND_CODE * (monster->GetStrength() - (2) + (2)));
			if(player->GetHealth() > 0){
				monster->subtractDamage(RAND_CODE * (player->GetStrength() - (2) + (2)));
			}
		 }
		}
		else {
			monster->subtractDamage(RAND_CODE * (player->GetStrength() - (2) + (2)));
			if(monster->GetHealth() > 0){
				player->subtractDamage(RAND_CODE * (monster->GetStrength() - (2) + (2)));
			}
		}
		}while(player->GetHealth() > 0 && monster->GetHealth() > 0);

		healthAtEnd = player->GetHealth();
		healthToRecover = (healthAtStart - healthAtEnd)/2;

		if(player->GetHealth() <= 0){ playerDead = true;}
		else if(monster->GetHealth() <= 0){ 
			monsterDead = true; 
			player->HealPlayer(healthToRecover);
			player->SetMoney(monster->GetMoneyDrop());
			int itemPick = (rand() % 100 + 1);
			if(itemPick <= monster->GetDropPercentage()){
				itemDrop = true;
			}else (itemDrop = false);
		}
}

bool StateBattle::GetMonsterDead() {
	return monsterDead;
}

bool StateBattle::GetPlayerDead() {
	return playerDead;
}

bool StateBattle::GetItemDrop(){
	return itemDrop;
}

void StateBattle::SetItemDrop(bool drop){
	itemDrop = drop;
}

void StateBattle::Enter() {
	monsterDead = false;
	playerDead = false;
}

void StateBattle::Exit() {

}

void StateBattle::Init(Game * context) {
	this->Init(context);
}

void StateBattle::Init(Game &context) {
	
}

bool StateBattle::GetContinuable() {
	return 0;
}

bool StateBattle::GetGameStarted() {
	return 0;
}
void StateBattle::SetGameStarted() {

}


void StateBattle::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_ESCAPE:  
				break;
			case SDLK_SPACE:
				CommenceBattle();
			default:
				break;
		}
	}
}

StateBattle::~StateBattle() {

}