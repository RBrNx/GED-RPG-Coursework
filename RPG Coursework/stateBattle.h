#pragma once

#include "gameState.h"
#include "Label.h"
#include "Player.h"
#include "stateMainMenu.h"

class Raider;
class Brute;

class StateBattle: public GameState {
public:
	StateBattle();
	void Draw(SDL_Window *window);
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Init(Game * context);
	void Init(Game &context);
	void Update(Game &context);
	void Enter();
	void Exit();
	bool GetContinuable();
	bool GetGameStarted();
	void SetGameStarted();
	~StateBattle();	

private:

	TTF_Font* textFont;
	Label * playerText;
	Label * enemyText;

	GameState * playState;
	GameState * mainMenuState;
	GameState * currentState;
	GameState * gameOverState;

	Raider * raider;
	Brute * brute;
	Brute * brute2;
	Brute * brute3;
	Player * player;
};