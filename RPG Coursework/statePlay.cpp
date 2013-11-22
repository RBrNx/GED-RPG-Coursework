#include "game.h"
#include "statePlay.h"
#include "Raider.h"
#include "gameOverState.h"

StatePlay::StatePlay() {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	srand((unsigned)time(NULL));

	player = new Player();
	raider = new Raider(player);	

	lastTime = clock();

	Enter();
}

void StatePlay::Update(Game &context)
{
	if (raider->Update() == true) {
			context.setState(gameOver);
	}
}

void StatePlay::Draw(SDL_Window *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	glClearColor(0.0, 0.0, 0.0, 0.0);

	raider->Draw(window);
	player->Draw(window);
	

    // Calculate ms/frame
    // Some OpenGL drivers will limit the frames to 60fps (16.66 ms/frame)
    // If so, expect to see the time to rapidly switch between 16 and 17...
    glColor3f(0.0f,0.0f,0.0f);
    currentTime = clock();
    // On some systems, CLOCKS_PER_SECOND is 1000, which makes the arithmetic below redundant
    // - but this is not necessarily the case on all systems
    float milliSecondsPerFrame = ((currentTime - lastTime)/(float)CLOCKS_PER_SEC*1000);
	
	SDL_GL_SwapWindow(window); // swap buffers
}

void StatePlay::Enter() {
	raider->SetXPos((float)rand()/RAND_MAX - 0.15f);
	raider->SetYPos((float)rand()/RAND_MAX - 0.15f);
	raider->SetHealth(12);
	raider->SetStrength(7);
	raider->SetSpeed(12);
}

void StatePlay::Exit() {

}

void StatePlay::Init(Game * context) {
	this->Init(context);
}

void StatePlay::Init(Game &context) {
	
}

void StatePlay::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		player->HandleSDLEvent(sdlEvent, context);
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_ESCAPE:
				context.setState(stateMenu);  break;
		
			default:
				break;
		}
	}
}

StatePlay::~StatePlay() {

}