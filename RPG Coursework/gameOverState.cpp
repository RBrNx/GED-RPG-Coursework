#include "gameOverState.h"
#include "statePlay.h"
#include "game.h"
#include "stateBattle.h"

gameOverState::gameOverState() {	
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36); //init font

	gameOverText = new Label();
	gameWinText = new Label();
	battleWinText = new Label();

	gameWinText->textToTexture("You have won the game!",textFont);
	battleWinText->textToTexture("You won the battle!",textFont);
	gameOverText->textToTexture("Game Over",textFont); //set up label
}

void gameOverState::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.4f, 0.4f, 0.4f, 0.0f); //grey background


	if(((StateBattle *)battleState)->GetMonsterDead() == true){
		battleWinText->draw(-0.8f,0.0f); //draw label
	}
	if(((StateBattle *)battleState)->GetPlayerDead() == true){
		gameOverText->draw(-0.8f,0.0f);
	}


	SDL_GL_SwapWindow(window);
}

void gameOverState::Enter() {

}

void gameOverState::Exit() {
}

bool gameOverState::GetContinuable() {
	return 0;
}

bool gameOverState::GetGameStarted() {
	return 0;
}
void gameOverState::SetGameStarted() {

}


void gameOverState::Init(Game * context) {

}

void gameOverState::Init(Game &context) {	
}

void gameOverState::Update(Game &context){

}

void gameOverState::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		if(((StateBattle *)battleState)->GetMonsterDead() == true){
			context.setState(PlayState);//go back to playstate after a win
		}
		if(((StateBattle *)battleState)->GetPlayerDead() == true){
			context.setState(stateMenu); //go back to main menu after a loss
		}
	}
}

gameOverState::~gameOverState(){

}

