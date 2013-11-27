#pragma once
#include "gameState.h"
#include "Label.h"

class stateSplash: public GameState {
private:
	Label * titleText;

	TTF_Font* textFont;
	TTF_Font* textFont72;
public:
	stateSplash();
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Draw(SDL_Window * window);
	void Init(Game * context);
	void Init(Game &context);
	void Update(Game &context);
	void Enter();
	void Exit();
	bool GetContinuable();
	bool GetGameStarted();
	void SetGameStarted();
	~stateSplash();

};