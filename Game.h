#ifndef __Game__
#define __Game__

#include <memory>

class Game
{

protected:
	Game() {};

	static Game* instance;

public:
	Game(Game& other) = delete;
	void operator=(const Game&) = delete;

	static Game* Instance();

	bool init(const char* title, int width, int
		height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { isRunning = false; }

	bool running() { return isRunning; }

private:

	bool isRunning;

	class SDL_Window* Window;
	class SDL_Renderer* Renderer;

};

#endif
