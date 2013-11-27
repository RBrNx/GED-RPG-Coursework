#include "game.h"
#include "statePlay.h"
#include "Raider.h"
#include "gameOverState.h"
#include "Brute.h"
#include "stateBattle.h"
#include "Fodder.h"

StatePlay::StatePlay() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24); //init font

	srand((unsigned)time(NULL));

	continuable = false; //bool variable if game is able to be continued
	gameStarted = false; //bool variable if game has already started
	enemyDelete = 0; //init variable

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

	player->Draw(window); //draw player
	
	continuable = true; //game is continuable

    glColor3f(0.0f,0.0f,0.0f);
    currentTime = clock();
   
    float milliSecondsPerFrame = ((currentTime - lastTime)/(float)CLOCKS_PER_SEC*1000);
	
	SDL_GL_SwapWindow(window); // swap buffers
}

void StatePlay::Enter() {
	//if game hasn't already been started, randomize all monster positions
	if(!gameStarted) {
		for(unsigned int i = 0; i < monsters.size(); i++){
			monsters[i]->SetXPos((float(rand())/float(RAND_MAX)) * (0.85f - (-1.0f)) + (-1.0f));
			monsters[i]->SetYPos((float(rand())/float(RAND_MAX)) * (0.85f - (-1.0f)) + (-1.0f));
		}
		gameStarted = true; //game already started is true
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
}