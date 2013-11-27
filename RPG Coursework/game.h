#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <GL/glew.h>
#include "Label.h"
// C stdlib and C time libraries for rand and time functions
#include <cstdlib>
#include <ctime>

// iostream for cin and cout
#include <iostream>

// stringstream and string
#include <sstream>
#include <string>
#include "gameState.h"

#if _DEBUG
	#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#pragma comment (lib, "glu32.lib")
#endif

extern GameState * stateMenu;
extern GameState * PlayState;
extern GameState * stateCredit;
extern GameState * gameOver;
extern GameState * battleState;
extern GameState * splashState;

class Game
{
public:
	Game();
	void init(void);
	void run(void);

	void setState(GameState *);
	void ExitFatalError(const char *);


	~Game();
	

private:
	SDL_Window * SetupRC(SDL_GLContext &);
	SDL_Window * Window;
	GameState * State;
	SDL_Event Event;

	bool isRunning;
};

