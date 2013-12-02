#pragma once

#include "gameState.h"
#include "Label.h"
#include "Player.h"
#include "stateMainMenu.h"
#include "Brute.h"
#include "Fodder.h"
#include "Raider.h"

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
	void CommenceBattle();
	bool GetMonsterDead();
	bool GetPlayerDead();
	bool GetItemDrop();
	void SetItemDrop(bool);
	void setupCharacters(Monster * monster, Player*);
	~StateBattle();	

private:

	bool monsterDead;
	bool itemDrop;
	bool playerDead;
	int healthAtStart;
	int healthAtEnd;
	int healthToRecover;
	TTF_Font* textFont;
	Label * playerText;
	Label * enemyText;
	Label * battleText;

	GameState * playState;
	GameState * mainMenuState;
	GameState * currentState;
	GameState * gameOverState;

	Monster * monster;
	Player * player;
};