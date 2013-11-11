#include "gameState.h"
#include "Label.h"

class stateMainMenu: public GameState {
private:
	Label * continueText;
	Label * loadText;
	Label * newgameText;
	Label * creditsText;
	Label * quitText;
	TTF_Font* textFont;

public:
	stateMainMenu();
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Draw(SDL_Window * window);
	void Init(Game * context);
	void Init(Game &context);
	void Enter();
	void Exit();
	~stateMainMenu();

};