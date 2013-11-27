#include "gameOverState.h"
#include "statePlay.h"
#include "game.h"

gameOverState::gameOverState() {	
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36); //init font

	gameOverText = new Label();
	gameOverText->textToTexture("Game Over",textFont); //set up label
}

void gameOverState::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.4f, 0.4f, 0.4f, 0.0f); //grey background

	gameOverText->draw(-0.8f,0.0f); //draw label

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
			context.setState(stateMenu); //go back to menu after any keypress
		}
	}

gameOverState::~gameOverState(){

}

