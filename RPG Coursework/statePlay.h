#pragma once

#include <vector>
#include "gameState.h"
#include "Label.h"
#include "Player.h"
#include "stateMainMenu.h"

using std::vector;

class Raider;
class Brute;
class Fodder;

class StatePlay: public GameState {
public:
	StatePlay();
	void Draw(SDL_Window *window);
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Init(Game * context);
	void Init(Game &context);
	void Update(Game &context);
	void Enter();
	bool GetContinuable();
	bool GetGameStarted();
	void SetGameStarted();
	void Exit();
	~StatePlay();	

private:
	int enemyDelete;
	bool continuable;
	bool gameStarted;
	clock_t currentTime;
	clock_t lastTime;

	TTF_Font* textFont;
	GameState * playState;
	GameState * mainMenuState;
	GameState * currentState;

	vector<Monster *> monsters;

	Player * player;
};