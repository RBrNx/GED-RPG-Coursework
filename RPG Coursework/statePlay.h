#pragma once

#include "gameState.h"
#include "Label.h"
#include "Player.h"

class Raider;

class StatePlay: public GameState {
public:
	StatePlay();
	void Draw(SDL_Window *window);
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Init(Game * context);
	void Init(Game &context);
	void Update(Game &context);
	void Enter();
	void Exit();
	~StatePlay();	

private:
	clock_t currentTime;
	clock_t lastTime;

	TTF_Font* textFont;
	GameState * playState;
	GameState * mainMenuState;
	GameState * currentState;

	Raider * raider;
	Raider * raider2;
	Raider * raider3;
	Player * player;
};