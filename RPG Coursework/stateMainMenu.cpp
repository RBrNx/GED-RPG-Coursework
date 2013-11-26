#include "stateMainMenu.h"
#include "statePlay.h"
#include "game.h"

stateMainMenu::stateMainMenu() {

	newgameText = new Label();
	continueText = new Label();
	loadText = new Label();
	creditsText = new Label();
	quitText = new Label();
	
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36);

	newgameText->textToTexture("New Game (N)",textFont);
	continueText->textToTexture("Continue Game (C)",textFont);
	loadText->textToTexture("Load Game (L)",textFont);
	creditsText->textToTexture("Credits (R)",textFont);
	quitText->textToTexture("Quit (Q/Esc)",textFont);
}

void stateMainMenu::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0f, 0.0f, 0.0f, 0.1f);

	newgameText->draw(-0.8f,0.0f);
	continueText->draw(-0.8f,-0.2f);
	loadText->draw(-0.8f,-0.4f);
	creditsText->draw(-0.8f,-0.6f);
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
}

void stateMainMenu::Update(Game &context){

}

bool stateMainMenu::GetContinuable() {
	return 0;
}

bool stateMainMenu::GetGameStarted() {
	return 0;
}
void stateMainMenu::SetGameStarted() {
}


void stateMainMenu::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
		case 'n': case 'N':
			PlayState->SetGameStarted();
			context.setState(PlayState);
			break;
		case 'q': case 'Q': case SDLK_ESCAPE: 
			exit(1); 
			break;
		case 'c': case 'C': 
			if (PlayState->GetContinuable() == true) {
				context.setState(PlayState);
			}
			break;
		case 'r': case 'R':
			context.setState(stateCredit);
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

