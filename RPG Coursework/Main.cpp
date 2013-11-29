#include "gameState.h"
#include "game.h"
#include "stateMainMenu.h"
#include "statePlay.h"
#include "stateCredits.h"
#include "gameOverState.h"
#include "stateBattle.h"
#include "stateSplash.h"
#include <iostream>
#include <Windows.h>

using namespace std;

GameState * PlayState;
GameState * stateMenu;
GameState * stateCredit;
GameState * gameOver;
GameState * battleState;
GameState * splashState;

// Program entry point
// SDL manages the actual WinMain entry point for us
int main(int argc, char *argv[])
{
	//FreeConsole(); //starts game without a console

	Game * newGame = new Game();
	newGame->init();
	stateMenu = new stateMainMenu(); //create all the states
	PlayState = new StatePlay();
	stateCredit = new stateCredits();
	battleState = new StateBattle();
	gameOver = new gameOverState();
	splashState = new stateSplash();
	newGame->setState(splashState); //load into the splash screen
	newGame->run();

	delete newGame;
	delete PlayState;
	delete stateMenu;
	delete stateCredit;
	delete gameOver;
	return 0;
}