#include "gameState.h"
#include "game.h"
#include "stateMainMenu.h"
#include "statePlay.h"

GameState * PlayState = new StatePlay();
GameState * stateMenu = new stateMainMenu();

// Program entry point
// SDL manages the actual WinMain entry point for us
int main(int argc, char *argv[])
{
	Game * newGame = new Game();
	newGame->init();
	newGame->setState(stateMenu);
	newGame->run();

	delete newGame;
	delete PlayState;
	delete stateMenu;
	return 0;
}