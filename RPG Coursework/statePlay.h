#pragma once

#include "gameState.h"
#include "Label.h"


class StatePlay: public GameState {
public:
	StatePlay();
	void Draw(SDL_Window *window);
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Init(Game * context);
	void Init(Game &context);
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

	float xsize;
	float ysize;
	float xpos;
	float ypos;

	float targetXSize;
	float targetYSize;
	float targetXPos;
	float targetYPos;

	int score;

	Label * scoreText;
	Label * playerText;
	Label * targetText;
};