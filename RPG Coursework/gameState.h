#pragma once
#include <SDL.h>
#include <ctime>

// GameState needs to refer to the Game object which needs to
// refer to GameState objects, which creates a circular dependency
// and causes problems with #includes 
// solution is to declare (but not define) the Game type here.
// so instead of 
// #include "Game.h"
// we have a 'forward declaration' of the class:
class Game;
// Game.h will still need to be included in the state implementation files

// Abstract game state class
// different game states will inherit from this
class GameState {
public:
	virtual ~GameState() { return; } // need a virtual destructor
	virtual void Draw(SDL_Window*) = 0;
	//virtual void init(Game * context) = 0;
	virtual void Init(Game&) = 0;
	virtual void Init(Game*) = 0;
	// Not using update function yet
	// virtual void update(void) = 0
	virtual void HandleSDLEvent(SDL_Event const &sdlEvent, Game &) = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;
};
