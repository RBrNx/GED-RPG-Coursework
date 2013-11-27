#include "stateMainMenu.h"
#include "statePlay.h"
#include "stateCredits.h"
#include "game.h"

stateCredits::stateCredits() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36);
	textFont72 = TTF_OpenFont("MavenPro-Regular.ttf", 72); //init fonts

	//creats the labels used in credits screen
	titleText = new Label();
	companyText = new Label();
	nameText = new Label();
	courseworkText = new Label();
	danielText = new Label();

	titleText->textToTexture("Credits",textFont72);
	companyText->textToTexture("Redbaron Games",textFont);
	nameText->textToTexture("Conor Watson",textFont);
	courseworkText->textToTexture("GED Coursework 2013",textFont);
	danielText->textToTexture("Creator of SDL Base - Daniel Livingston",textFont);
}

void stateCredits::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	//draws labels
	titleText->draw(-0.25f,0.8f);
	companyText->draw(-0.3f,0.6f);
	nameText->draw(-0.25f,0.4f);
	courseworkText->draw(-0.4f,-0.4f);
	danielText->draw(-0.65f,-0.6f);

	SDL_GL_SwapWindow(window);
}

void stateCredits::Enter() {

}

void stateCredits::Exit() {
}

bool stateCredits::GetContinuable() {
	return 0;
}

bool stateCredits::GetGameStarted() {
	return 0;
}
void stateCredits::SetGameStarted() {

}


void stateCredits::Init(Game * context) {

}

void stateCredits::Update(Game &context){
	//after 30 seconds (30000 ticks) the game returns to main menu
	if(SDL_GetTicks() >=30000){
		context.setState(stateMenu);
	}
}

void stateCredits::Init(Game &context) {
	
}

void stateCredits::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	//game returns to menu on any keypress
	if(sdlEvent.type == SDL_KEYDOWN) {
		context.setState(stateMenu);
		}
	}

stateCredits::~stateCredits(){

}

