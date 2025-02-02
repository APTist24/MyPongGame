#include <Game/Game.h>
#include <SDL3/SDL.h>
#include <GL/glew.h>
// #include <SDL_ttf.h>
#include <iostream>

#include <InputHandler/InputHandler.h>
#include <States/MenuState.h>
// #include <SDL_mixer.h>

Game* Game::instance = nullptr;

Game* Game::Instance()
{
	if (!instance)
		instance = new Game();
	return instance;
}

bool Game::init(const char* title, int width,
	int height, bool fullscreen)
{
	// Устанавливаем атрибуты OpenGL перед созданием окна
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Флаги окна
	int flags = SDL_WINDOW_OPENGL;
	if(fullscreen) 
		flags |= SDL_WINDOW_FULLSCREEN;

	// Инициализация SDL
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
		std::cerr << "SDL initialization failed: " << SDL_GetError() << "\n";
		return false;
	}

	// Создаем окно с OpenGL контекстом
	m_window = SDL_CreateWindow(title, 
							   width, 
							   height, 
							   flags);
	if(!m_window) {
		std::cerr << "Window creation failed: " << SDL_GetError() << "\n";
		return false;
	}

	// Создаем OpenGL контекст
	m_glContext = SDL_GL_CreateContext(m_window);
	if(!m_glContext) {
		std::cerr << "OpenGL context creation failed: " << SDL_GetError() << "\n";
		return false;
	}

	// Инициализация GLEW
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		std::cerr << "Failed to initialize GLEW\n";
		return false;
	}

	// Настройка OpenGL
	glViewport(0, 0, width, height);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Инициализация аудио
	// if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
	// 	std::cerr << "SDL_mixer initialization failed: " << Mix_GetError() << "\n";
	// }
	//
	// // Инициализация шрифтов (если нужно)
	// if(TTF_Init() == -1) {
	// 	std::cerr << "SDL_ttf initialization failed: " << TTF_GetError() << "\n";
	// }

	// Инициализация игровых состояний
	StateManager = new GameStateMachine();
	StateManager->changeState(std::make_unique<MenuState>());

	isRunning = true;
	return true;
	// int flags = 0;
	// if (fullscreen)
	// 	flags = SDL_WINDOW_FULLSCREEN;
	//
	// if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
	// 	std::cerr << "Unable to init SDL: " << SDL_GetError() << std::endl;
	// 	return false;
	// }
	//
	// Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	// if (!Window) {
	// 	std::cerr << "Unable to create window: " << SDL_GetError() << std::endl;
	// 	return false;
	// }
	//
	// m_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);
	// if (!m_window) {
	// 	std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
	// 	return false;
	// }
	//
	// Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	// if (!Renderer) {
	// 	std::cerr << "Unable to create renderer: " << SDL_GetError() << std::endl;
	// 	return false;
	// }
	//
	// if (TTF_Init() == -1)
	// {
	// 	std::cerr << "Unable to init TTF: " << TTF_GetError() << std::endl;
	// }
	//
	// Font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 35);
	// if (!Font) {
	// 	std::cerr << "Unable to open font: " << TTF_GetError() << std::endl;
	// }
	//
	// Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
	//
	// isRunning = true; //main loop boolean, if false, stop game loop
	//
	// StateManager = new GameStateMachine();
	// StateManager->changeState(std::move(std::make_unique<MenuState>()));
	//
	// return true;
}

void Game::render()
{
	// SDL_RenderClear(Renderer); // clear the renderer to the draw color
	//
	// StateManager->render();
	//
	// SDL_RenderPresent(Renderer); // draw to the screen
}

void Game::update()
{
	// StateManager->update();
}

void Game::handleEvents()
{
	// InputHandler::Instance()->update();

}

void Game::clean()
{
	// TTF_CloseFont(Font);
	// TTF_Quit();
	// SDL_DestroyWindow(Window);
	// SDL_DestroyRenderer(Renderer);
	// SDL_Quit();
}