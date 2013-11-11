#include "game.h"
#include "statePlay.h"

StatePlay::StatePlay() {
	Enter();
}

void StatePlay::Draw(SDL_Window *window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window

	// draw player
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	  glVertex3f (xpos, ypos, 0.0); // first corner
	  glVertex3f (xpos+xsize, ypos, 0.0); // second corner
	  glVertex3f (xpos+xsize, ypos+ysize, 0.0); // third corner
	  glVertex3f (xpos, ypos+ysize, 0.0); // fourth corner
	glEnd();
	playerText->textToTexture("Player",textFont);
	playerText->draw(xpos, ypos+ysize);

    // draw target
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
      glVertex3f (targetXPos, targetYPos, 0.0); // first corner
      glVertex3f (targetXPos+targetXSize, targetYPos, 0.0); // second corner
      glVertex3f (targetXPos+targetXSize, targetYPos+targetYSize, 0.0); // third corner
      glVertex3f (targetXPos, targetYPos+targetYSize, 0.0); // fourth corner
    glEnd();
	targetText->textToTexture("Target",textFont);
	targetText->draw(targetXPos, targetYPos+targetYSize);
    
    if ( (targetXPos >= xpos) && (targetXPos+targetXSize <= xpos+xsize)	// cursor surrounds target in x
	  && (targetYPos >= ypos) && (targetYPos+targetYSize <= ypos+ysize) ) // cursor surrounds target in y
    {
		score += 100; // congrats, player has scored!
		// randomize the new target position
		targetXPos = (float)rand()/RAND_MAX - 0.75f;
		targetYPos = (float)rand()/RAND_MAX - 0.75f;
    }

    // Calculate ms/frame
    // Some OpenGL drivers will limit the frames to 60fps (16.66 ms/frame)
    // If so, expect to see the time to rapidly switch between 16 and 17...
    glColor3f(1.0,1.0,1.0);
    currentTime = clock();
    // On some systems, CLOCKS_PER_SECOND is 1000, which makes the arithmetic below redundant
    // - but this is not necessarily the case on all systems
    float milliSecondsPerFrame = ((currentTime - lastTime)/(float)CLOCKS_PER_SEC*1000);

    // Print out the score and frame time information
    std::stringstream strStream;
    strStream << "Score:" << score;
    strStream << "          ms/frame: " << milliSecondsPerFrame;
	
	scoreText->textToTexture(strStream.str().c_str(), textFont);
	scoreText->draw(-0.9,0.9);
    lastTime = clock();

	SDL_GL_SwapWindow(window); // swap buffers
}

void StatePlay::Enter() {
	targetXSize = 0.1f;
	targetYSize = 0.1f;
	targetXPos = 0.0f;
	targetYPos = 0.0f;

	xsize = 0.15f;
	ysize = 0.15f;
	xpos = 0.0f;
	ypos = 0.0f;

	score = 0;
}

void StatePlay::Exit() {

}

void StatePlay::Init(Game * context) {
	this->Init(context);
}

void StatePlay::Init(Game &context) {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	srand((unsigned)time(NULL));

	targetXPos = (float)rand()/RAND_MAX - 0.75f;
	targetYPos = (float)rand()/RAND_MAX - 0.75f;

	lastTime = clock();
	
	playerText = new Label();
	scoreText = new Label();
	targetText = new Label();
}

void StatePlay::HandleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if(sdlEvent.type == SDL_KEYDOWN) {
		switch(sdlEvent.key.keysym.sym) {
			case SDLK_ESCAPE:
				context.setState(stateMenu);  break;
			case SDLK_UP:
			case 'w': case 'W': 
				ypos += 0.05f;
				break;

			case SDLK_DOWN:
			case 's': case 'S':
				ypos -= 0.05f;
				break;

			case SDLK_LEFT:
			case 'a': case 'A': 
				xpos -= 0.05f;
				break;

			case SDLK_RIGHT:
			case 'd': case 'D':
				xpos += 0.05f;
				break;

			default:
				break;
		}
	}
}

StatePlay::~StatePlay() {

}