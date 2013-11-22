#include "gameState.h"
#include "Label.h"

class stateCredits: public GameState {
private:
	Label * titleText;
	Label * companyText;
	Label * nameText;
	Label * courseworkText;
	Label * danielText;

	TTF_Font* textFont;
	TTF_Font* textFont72;
public:
	stateCredits();
	void HandleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void Draw(SDL_Window * window);
	void Init(Game * context);
	void Init(Game &context);
	void Update(Game &context);
	void Enter();
	void Exit();
	~stateCredits();

};