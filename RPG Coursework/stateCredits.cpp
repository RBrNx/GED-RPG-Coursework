#include "stateMainMenu.h"
#include "statePlay.h"
#include "stateCredits.h"
#include "game.h"

stateCredits::stateCredits() {

}

void stateCredits::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

	titleText->textToTexture("Credits",textFont72);
	titleText->draw(-0.25f,0.8f);

	companyText->textToTexture("Redbaron Games",textFont);
	companyText->draw(-0.3f,0.6f);

	nameText->textToTexture("Conor Watson",textFont);
	nameText->draw(-0.25f,0.4f);

	courseworkText->textToTexture("GED Coursework 2013",textFont);
	courseworkText->draw(-0.4f,-0.4f);

	danielText->textToTexture("Creator of SDL Base - Daniel Livingston",textFont);
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

}

void stateCredits::Init(Game &context) {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36);
	textFont72 = TTF_OpenFont("MavenPro-Regular.ttf", 72);
	
	titleText = new Label();
	companyText = new Label();
	nameText = new Label();
	courseworkText = new Label();
	danielText = new Label();
}

void stateCredits::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		context.setState(stateMenu);
		}
	}

stateCredits::~stateCredits(){

}

