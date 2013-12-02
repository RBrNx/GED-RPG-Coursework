#include "stateCharacterSelect.h"
#include "game.h"


stateCharacterSelect::stateCharacterSelect() {	
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 36); //init font

	characterText = new Label();

	characterText->textToTexture("Character Selection",textFont);
}

void stateCharacterSelect::Draw(SDL_Window * window) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.4f, 0.4f, 0.4f, 0.0f); //grey background

	glBegin(GL_POLYGON); //draws box
	
		glColor3f(1.0,0.0,0.0);
      
		glVertex2f(-0.9, 0.9); 
		glVertex2f(-0.9, 0.4); 
		glVertex2f(-0.4, 0.4);
		glVertex2f(-0.4, 0.9); 
    
	glEnd();

	characterText->draw(-0.3,0.9); //draws label


	SDL_GL_SwapWindow(window);
}

void stateCharacterSelect::Enter() {

}

void stateCharacterSelect::Exit() {
}

void stateCharacterSelect::Init(Game * context) {

}

void stateCharacterSelect::Init(Game &context) {	
}

void stateCharacterSelect::Update(Game &context){

}

bool stateCharacterSelect::GetContinuable(){
	return 0;
}

bool stateCharacterSelect::GetGameStarted(){
	return 0;
}

void stateCharacterSelect::SetGameStarted(){

}


void stateCharacterSelect::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_SPACE:
				context.setState(PlayState);
		}
	}
}

stateCharacterSelect::~stateCharacterSelect(){

}

