#include "game.h"
#include "statePlay.h"


Game::Game()
	: isRunning(false) {
		State = NULL;
}

// We should be able to detect when errors occur with SDL if there are 
// unrecoverable errors, then we need to print an error message and quit the program
void Game::ExitFatalError(const char *message)
{
    std::cout << message << " " << SDL_GetError();
    SDL_Quit();
    exit(1);
}


// Set up rendering context
// Sets values for, and creates an OpenGL context for use with SDL
SDL_Window * Game::SetupRC(SDL_GLContext &context)
{
	SDL_Window *window;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize video
        ExitFatalError("Unable to initialize SDL"); 

    // Request an OpenGL 2.1 context.
	// If you request a context not supported by your drivers, no OpenGL context will be created
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); // 8 bit alpha buffering

	// Optional: Turn on x4 multisampling anti-aliasing (MSAA)
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
 
    // Create 800x800 window
    window = SDL_CreateWindow("SDL OpenGL Demo for GED",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
	if (!window) // Check window was created OK
        ExitFatalError("Unable to create window");
 
    context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
    SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate

	// set up TrueType / SDL_ttf
	if (TTF_Init()== -1)
		ExitFatalError("TTF failed to initialise.");

	return window;
}

void Game::init()
{
	srand((unsigned)time(NULL));
	SDL_GLContext glContext; // OpenGL context handle
    Window = SetupRC(glContext); // Create window and render context
	if(Window !=NULL) {
		isRunning = true; }
	else { ExitFatalError("Window failed to open");
	}
}

void Game::run()
{
	// unlike GLUT, SDL requires you to write your own event loop
	// This puts much more power in the hands of the programmer
	// This simple loop only responds to the window being closed.
	while (isRunning)	// the event loop
	{
		while (SDL_PollEvent(&Event))
		{
			if (Event.type == SDL_QUIT)
				isRunning = false;
			else{
				State->HandleSDLEvent(Event, *this);	
			}

		}
		
		State->Update(*this); // this is the place to put a call to the game update function
		State->Draw(Window); // call the draw function
	}
	SDL_DestroyWindow(Window);
	SDL_Quit();
}

void Game::setState(GameState * state) {
	if(State !=NULL) {
		State->Exit();
	}
	State = state;
	State->Enter();
	State->Init(*this);
}


Game::~Game()
{
	State = NULL;
}