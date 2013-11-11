#include "stateMainMenu.h"
#include "statePlay.h"
#include "game.h"

stateMainMenu::stateMainMenu() {

}

void stateMainMenu::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);

	SDL_GL_SwapWindow(window);
}

void stateMainMenu::Enter() {

}

void stateMainMenu::Exit() {
}

void stateMainMenu::Init(Game * context) {
	this->Init(context);
}

void stateMainMenu::Init(Game &context) {

}

void stateMainMenu::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
		case SDLK_ESCAPE:
			context.setState(PlayState); break;

		default:
			break;
		}
	}
}

stateMainMenu::~stateMainMenu(){

}

