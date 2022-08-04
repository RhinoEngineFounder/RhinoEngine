#pragma once
#include <SDL2/SDL.h>
#include "Component.h"

typedef SDL_KeyCode     KeyCode;
typedef const Uint8*       InputInfo;

/*class InputComponent : public Component
{
public:
    InputComponent();
    ~InputComponent();

    void SetInput(InputInfo* inpt) 
    { 
        lastInput = input;
        input = inpt; 
    }

    InputInfo* GetInput() { return input; }
    InputInfo* GetLastInput() { return lastInput; }

    bool isKeyPressed(KeyCode code)
    {
        if(input->key.keysym.sym == code)
            return true;
        return false;
    }

    bool isKeyHeldDown(KeyCode code)
    {
        if(input == nullptr)
            return false;

        if(input->key.keysym.sym == code && lastInput->key.keysym.sym == code)
            return true;
        return false;
    }

private:
    InputInfo* input;
    InputInfo* lastInput;
};*/