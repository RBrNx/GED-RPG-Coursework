#include "stateMainMenu.h"
#include "statePlay.h"
#include "game.h"

stateMainMenu::stateMainMenu() {

}

void stateMainMenu::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 0.1f);

	newgameText->textToTexture("New Game (N)",textFont);
	newgameText->draw(-0.8f,0.0f);
	
	continueText->textToTexture("Continue Game (C)",textFont);
	continueText->draw(-0.8f,-0.2f);
	
	loadText->textToTexture("Load Game (L)",textFont);
	loadText->draw(-0.8f,-0.4f);
	
	creditsText->textToTexture("Credits (R)",textFont);
	creditsText->draw(-0.8f,-0.6f);
	
	quitText->textToTexture("Quit (Q/Esc)",textFont);
	quitText->draw(-0.8f,-0.8f);

	SDL_GL_SwapWindow(window);
}

void stateMainMenu::Enter() {

}

void stateMainMenu::Exit() {
}

void stateMainMenu::Init(Game * context) {

}

void stateMainMenu::Init(Game &context) {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36);
	
	newgameText = new Label();
	continueText = new Label();
	loadText = new Label();
	creditsText = new Label();
	quitText = new Label();
	
}

void stateMainMenu::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
		case 'n': case 'N':
			context.setState(PlayState); 
			break;
		case 'q': case 'Q': case SDLK_ESCAPE: 
			exit(1); 
			break;
		case 'c': case 'C': 
			//continue game
			break;
		case 'r': case 'R':
			//roll credits
			break;
		case 'l': case 'L': 
			//load game
			break;

		default:
			break;
		}
	}
}

stateMainMenu::~stateMainMenu(){

}

