#pragma once
#include <SDL2/SDL.h>

typedef const Uint8*    InputInfo;
typedef SDL_Scancode    scancode;
typedef SDL_EventType   eventtype;

// pain :D
#define KeyCode_w SDL_SCANCODE_W
#define KeyCode_a SDL_SCANCODE_A
#define KeyCode_s SDL_SCANCODE_S
#define KeyCode_d SDL_SCANCODE_D
#define KeyCode_space SDLK_SPACE
#define KeyCode_shift SDL_SCANCODE_LSHIFT || SDL_SCANCODE_RSHIFT

class Input
{
public:
    Input() {}
    ~Input() {}

    static bool isKeyHeldDown(scancode code)
    {
        const Uint8 *input = SDL_GetKeyboardState(nullptr);
        if (input[code])
            return true;
        return false;
    }

    static bool isKeyPressed(SDL_KeyCode code)
    {
        SDL_Event key;
        while(SDL_PollEvent(&key))
        {
            if(key.key.keysym.sym == code)
                return true;
        }
        return false;
    }

    static bool isKeyPressed(SDL_EventType event)
    {
        SDL_Event key;
        while(SDL_PollEvent(&key))
        {
            if(key.type == event)
                return true;
        }
        return false;
    }
};