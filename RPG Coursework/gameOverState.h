#pragma once

#include "gameState.h"
#include "Label.h"
#include "Raider.h"

class gameOverState: public GameState
{
public:
	gameOverState(void);
	void Draw(SDL_Window *window);
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Init(Game * context);
	void Init(Game &context);
	void Update(Game &context);
	void Enter();
	void Exit();
	~gameOverState(void);

private:
	TTF_Font* textFont;
	Label * gameOverText;
};

