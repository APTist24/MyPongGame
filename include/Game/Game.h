#pragma once

#include <SDL3/SDL_video.h>
#include <StatesManager/GameStateMachine.h>

class SDL_Window;

class Game
{
protected:
    Game()
    {
    };

    static Game* instance;

public:
    Game(Game& other) = delete;
    void operator=(const Game&) = delete;

    static Game* Instance();

    bool init(const char* title, int width, int height, bool fullscreen);

    void render();
    
    void update();
    
    void handleEvents();
    
    void clean();
    
    void quit() { isRunning = false; }

    bool running() { return isRunning; }

    struct SDL_Renderer* getRenderer() { return Renderer; }

    struct _TTF_Font* getFont() { return Font; }

    GameStateMachine* getStateMachine() { return StateManager; }

private:
    bool isRunning;

private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    struct SDL_Renderer* Renderer;
    struct _TTF_Font* Font;

    GameStateMachine* StateManager;
};
