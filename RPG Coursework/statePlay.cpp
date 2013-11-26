#include "game.h"
#include "statePlay.h"
#include "Raider.h"
#include "gameOverState.h"
#include "Brute.h"
#include "stateBattle.h"
#include "Fodder.h"

StatePlay::StatePlay() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	srand((unsigned)time(NULL));

	continuable = false;
	gameStarted = false;
	enemyDelete = 0;

	player = new Player();

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
	for(unsigned int i = 0; i < monsters.size(); i++) {
		if(monsters[i] != NULL) {
			if (monsters[i]->Update()) {
				context.setState(battleState);
				enemyDelete = i+1;
			}
		}
	}
}

void StatePlay::Draw(SDL_Window *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	glClearColor(0.0, 0.0, 0.0, 0.0);

	for(unsigned int i = 0; i < monsters.size(); i++) {
		if(monsters[i] != NULL) {
			monsters[i]->Draw(window);
		}
	}

	player->Draw(window);
	
	continuable = true;

    glColor3f(0.0f,0.0f,0.0f);
    currentTime = clock();
   
    float milliSecondsPerFrame = ((currentTime - lastTime)/(float)CLOCKS_PER_SEC*1000);
	
	SDL_GL_SwapWindow(window); // swap buffers
}

void StatePlay::Enter() {
	if(!gameStarted) {
		for(unsigned int i = 0; i < monsters.size(); i++){
			monsters[i]->SetXPos((float(rand())/float(RAND_MAX)) * (0.85f - (-1.0f)) + (-1.0f));
			monsters[i]->SetYPos((float(rand())/float(RAND_MAX)) * (0.85f - (-1.0f)) + (-1.0f));
		}
	
		gameStarted = true;
	}
	
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
		player->HandleSDLEvent(sdlEvent, context);
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_ESCAPE:
				context.setState(stateMenu);  break;
		
			default:
				break;
		}
	}
}

StatePlay::~StatePlay() {
	delete player;
	for(unsigned int i = 0; i < monsters.size(); i++) {
		delete monsters[i];
	}
}