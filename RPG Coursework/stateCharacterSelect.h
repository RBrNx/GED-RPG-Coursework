#pragma once

#include "gameState.h"
#include "Label.h"

class stateCharacterSelect: public GameState
{
public:
	stateCharacterSelect(void);
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
	~stateCharacterSelect(void);

private:
	TTF_Font* textFont;
	Label * characterText;
};

