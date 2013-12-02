#include "game.h"
#include "statePlay.h"
#include "Raider.h"
#include "gameOverState.h"
#include "Brute.h"
#include "stateBattle.h"
#include "Fodder.h"
#include "HealthPack.h"
#include "CombatPack.h"
#include "StimulantPack.h"
#include <sstream>

#define RAND_CODE (float(rand())/float(RAND_MAX))

StatePlay::StatePlay() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	srand((unsigned)time(NULL));

	continuable = false; //bool variable if game is able to be continued
	gameStarted = false; //bool variable if game has already started
	enemyDelete = 0; //init variable
	itemDelete = 0; //init variable
	itemSelect = 0;

	player = new Player(); //create player

	//create 9 monsters
		
	monsters.push_back(new Raider(player));	
	monsters.push_back(new Brute(player));
	monsters.push_back(new Brute(player));
	monsters.push_back(new Brute(player));
	monsters.push_back(new Fodder(player));
	monsters.push_back(new Fodder(player));
	monsters.push_back(new Fodder(player));
	monsters.push_back(new Fodder(player));
	monsters.push_back(new Fodder(player));

	items.push_back(new HealthPack(player));
	items.push_back(new HealthPack(player));
	items.push_back(new CombatPack(player));
	items.push_back(new CombatPack(player));
	items.push_back(new StimulantPack(player));

	lastTime = clock();

	Enter();
}

void StatePlay::Update(Game &context)
{
	//for all the monsters in the vector, call update and check for collisions
	for(unsigned int i = 0; i < monsters.size(); i++) {
		if(monsters[i] != NULL) {
			if (monsters[i]->Update()) {
				context.setState(battleState);
				((StateBattle *)battleState)->setupCharacters(monsters[i],player); //pass player data to battle state
				enemyDelete = i+1; 
			}
		}
	}

	for(unsigned int i = 0; i < items.size(); i++){
		if(items[i] != NULL) {
			if(items[i]->Update() == 1) {
				if(player->GetHealth() >= 10) {
					player->HealPlayer(1);
					itemDelete = i+1;
				}else {
					(player->SetHealth(10));
					itemDelete = i+1;
				}
			}
			if(items[i]->Update() == 2) {
				player->increaseStrength(2);
				itemDelete = i+1;
			}
			if(items[i]->Update() == 3) {
				player->increaseSpeed(1);
				itemDelete = i+1;
			}
		}
	}

		if(itemDelete != NULL) {
		delete items[itemDelete - 1];
		items[itemDelete - 1] = NULL;
	}
		if(((StateBattle*)battleState)->GetItemDrop() == true){
		itemSelect = (rand() % 100 - 1);
		if(itemSelect >= 1 && itemSelect <= 60){
			HP = new HealthPack(player);
			HP->SetXPos(player->GetXPos());
			HP->SetYPos(player->GetYPos());
			delete HP;
			std::cout << "Health pack dropped" << std::endl;
		}
		if(itemSelect >60 && itemSelect <= 80){
			CP = new CombatPack(player);
			CP->SetXPos(player->GetXPos());
			CP->SetYPos(player->GetYPos());
			std::cout << "Combat pack dropped" << std::endl;
		}
		if(itemSelect >80 && itemSelect <= 100){
			SP = new StimulantPack(player);
			SP->SetXPos(player->GetXPos());
			SP->SetYPos(player->GetYPos());
			std::cout << "Stimulant pack dropped" << std::endl;
		}
		((StateBattle*)battleState)->SetItemDrop(false);
		
	}		
}

void StatePlay::Draw(SDL_Window *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//for all monsters in vector call draw function
	for(unsigned int i = 0; i < monsters.size(); i++) {
		if(monsters[i] != NULL) {
			monsters[i]->Draw(window);
		}
	}

	for(unsigned int i = 0; i < items.size(); i++) {
		if(items[i] != NULL) {
			items[i]->Draw(window);
		}
	}

	player->Draw(window); //draw player
	continuable = true; //game is continuable

	std::stringstream strStream;
	strStream << "Health: " << player->GetHealth() << "    Strength: " << player->GetStrength() << "    Speed: " << player->GetSpeed() << "    Money: " << player->GetMoney() << std::endl;
	Label statsStream;
	statsStream.textToTexture(strStream.str().c_str(), textFont);
	statsStream.draw(-0.4f,-1.0f);

	SDL_GL_SwapWindow(window); // swap buffers
}

void StatePlay::Enter() {
	//if game hasn't already been started, randomize all monster positions
	if(!gameStarted) {
		for(unsigned int i = 0; i < monsters.size(); i++){
			monsters[i]->SetXPos(RAND_CODE * (0.85f - (-1.0f)) + (-1.0f));
			monsters[i]->SetYPos(RAND_CODE * (0.85f - (-0.9f)) + (-0.9f));
		}
		for(unsigned int i = 0; i < monsters.size(); i++){// checks to see if any collisions happen at the start of the game, if they do - randomise the spawns again
			if(monsters[i]->Update() != NULL){
				monsters[i]->SetXPos(RAND_CODE * (0.85f - (-1.0f)) + (-1.0f));
				monsters[i]->SetYPos(RAND_CODE * (0.85f - (-0.9f)) + (-0.9f));
			}
		}
		//randomizes all item spawns
		for(unsigned int i = 0; i < items.size(); i++){
			items[i]->SetXPos(RAND_CODE * (0.85f - (-1.0f)) + (-1.0f));
			items[i]->SetYPos(RAND_CODE * (0.85f - (-0.9f)) + (-0.9f));
		}
		for(unsigned int i = 0; i < items.size(); i++){// checks to see if any collisions happen at the start of the game, if they do - randomise the spawns again
			if(items[i]->Update() != NULL){
				items[i]->SetXPos(RAND_CODE * (0.85f - (-1.0f)) + (-1.0f));
				items[i]->SetYPos(RAND_CODE * (0.85f - (-0.9f)) + (-0.9f));
			}
		}
		gameStarted = true; //game already started is set to true
	}
	
	//delete monsters that have been collided with and lost. puny monsters!
	if(enemyDelete != NULL) {
		delete monsters[enemyDelete - 1];
		monsters[enemyDelete - 1] = NULL;
	}
}

void StatePlay::Exit() {

}

bool StatePlay::GetContinuable() {
	return continuable;
}

bool StatePlay::GetGameStarted() {
	return gameStarted;
}
void StatePlay::SetGameStarted() {
	gameStarted = false;
}

void StatePlay::Init(Game * context) {
	this->Init(context);
}

void StatePlay::Init(Game &context) {
	
}

void StatePlay::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		//call players handle event for movement
		player->HandleSDLEvent(sdlEvent, context);
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_ESCAPE:
				//return to menu on 'Esc' press
				context.setState(stateMenu);  break;
			default:
				break;
		}
	}
}

StatePlay::~StatePlay() {
	delete player;
	//for all monsters in the vector, delete them
	for(unsigned int i = 0; i < monsters.size(); i++) {
		delete monsters[i];
	}
	for(unsigned int i = 0; i < items.size(); i++) {
		delete items[i];
	}
}