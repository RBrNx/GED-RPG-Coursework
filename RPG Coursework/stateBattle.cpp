#include "game.h"
#include "stateBattle.h"
#include "Raider.h"
#include "gameOverState.h"
#include "Brute.h"
#include "Label.h"
#include <sstream>

StateBattle::StateBattle() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
		
	playerText = new Label();
	enemyText = new Label();

	playerText->textToTexture("Player",textFont);

	enemyText->textToTexture("Enemy",textFont);
}

void StateBattle::Update(Game &context)
{

}

void StateBattle::Draw(SDL_Window *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	glClearColor(0.0, 0.0, 0.0, 0.0);

	 glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2f(-1.0f, -1.0f); 
		glVertex2f(-1.0f+0.5f, -1.0f); 
		glVertex2f(-1.0f+0.5f, -1.0f+0.5f);
		glVertex2f(-1.0f, -1.0f+0.5f); 
	glEnd();

	playerText->draw(-0.8f,-0.5f);

	glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		glVertex2f(0.5f, 0.5f); 
		glVertex2f(0.5f+0.5f, 0.5f); 
		glVertex2f(0.5f+0.5f, 0.5f+0.5);
		glVertex2f(0.5f, 0.5f+0.5f); 
	glEnd();

	enemyText->draw(0.7f, 0.45f);

/*	std::stringstream strStream;
	strStream << "Health" << player->GetHealth() << std::endl;
	strStream << "Strength" << player->GetStrength() << std::endl;
	strStream << "Speed" << player->GetSpeed() << std::endl;
	Label playerStream(0.0f,0.0f);
	playerStream.textToTexture(strStream.str().c_str(), textFont);
	*/
	SDL_GL_SwapWindow(window); // swap buffers
}

void StateBattle::Enter() {

}

void StateBattle::Exit() {

}

void StateBattle::Init(Game * context) {
	this->Init(context);
}

void StateBattle::Init(Game &context) {
	
}

bool StateBattle::GetContinuable() {
	return 0;
}

bool StateBattle::GetGameStarted() {
	return 0;
}
void StateBattle::SetGameStarted() {

}


void StateBattle::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_ESCAPE:
				context.setState(PlayState);  
				break;
			default:
				break;
		}
	}
}

StateBattle::~StateBattle() {

}