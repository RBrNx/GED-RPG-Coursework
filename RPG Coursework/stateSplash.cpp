#include "stateMainMenu.h"
#include "statePlay.h"
#include "stateSplash.h"
#include "game.h"

stateSplash::stateSplash() {

}

void stateSplash::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	titleText->textToTexture("Fantasy RPG",textFont72); //set up and draw label
	titleText->draw(-0.45f,0.0f);

	SDL_GL_SwapWindow(window);
}

void stateSplash::Enter() {

}

void stateSplash::Exit() {
}

bool stateSplash::GetContinuable() {
	return 0;
}

bool stateSplash::GetGameStarted() {
	return 0;
}
void stateSplash::SetGameStarted() {

}


void stateSplash::Init(Game * context) {

}

void stateSplash::Update(Game &context){
	//after 3 seconds load in menu
	if(SDL_GetTicks() >=3000){
		context.setState(stateMenu);
	}
}

void stateSplash::Init(Game &context) {
	textFont72 = TTF_OpenFont("MavenPro-Regular.ttf", 72); //init font
	
	titleText = new Label(); //creates label

}

void stateSplash::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	//on any keypress go to main menu
	if(sdlEvent.type == SDL_KEYDOWN) {
		context.setState(stateMenu);
		}
	}

stateSplash::~stateSplash(){

}

