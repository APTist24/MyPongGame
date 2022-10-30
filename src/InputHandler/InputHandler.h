#ifndef __InputHandler__
#define __InputHandler__

#include <vector>


enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:

	InputHandler(InputHandler&) = delete;
	void operator=(const InputHandler&) = delete;

	static InputHandler* Instance();

	void update();
	bool isKeyDown(class SDL_Scancode key);

private:
	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	std::vector<bool> m_mouseButtonStates;

private:

	InputHandler() {};

	static InputHandler* s_pInstance;

	Vector2D* m_mousePosition = nullptr;

	Uint8* m_keystates;

};

#endif
