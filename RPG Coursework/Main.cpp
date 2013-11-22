#include "gameState.h"
#include "game.h"
#include "stateMainMenu.h"
#include "statePlay.h"
#include "stateCredits.h"
#include "gameOverState.h"

#include <iostream>

using namespace std;

GameState * PlayState;
GameState * stateMenu;
GameState * stateCredit;
GameState * gameOver;

// Program entry point
// SDL manages the actual WinMain entry point for us
int main(int argc, char *argv[])
{
	Game * newGame = new Game();
	newGame->init();
	stateMenu = new stateMainMenu();
	PlayState = new StatePlay();
	stateCredit = new stateCredits();
	gameOver = new gameOverState();
	newGame->setState(stateMenu);
	newGame->run();

	delete newGame;
	delete PlayState;
	delete stateMenu;
	delete stateCredit;
	delete gameOver;
	return 0;
}