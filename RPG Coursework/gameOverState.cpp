#include "gameOverState.h"
#include "statePlay.h"
#include "game.h"

gameOverState::gameOverState() {	
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36);

	gameOverText = new Label();
	gameOverText->textToTexture("Game Over",textFont);
}

void gameOverState::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.4f, 0.4f, 0.4f, 0.0f);

	gameOverText->draw(-0.8f,0.0f);

	SDL_GL_SwapWindow(window);
}

void gameOverState::Enter() {

}

void gameOverState::Exit() {
}

void gameOverState::Init(Game * context) {

}

void gameOverState::Init(Game &context) {	
}

void gameOverState::Update(Game &context){

}

void gameOverState::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
			context.setState(stateMenu); 
		}
	}

gameOverState::~gameOverState(){

}

