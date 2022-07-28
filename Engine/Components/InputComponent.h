#pragma once
#include "Component.h"
#include "../Events/Input.h"

typedef SDL_KeyCode KeyCode;

class InputComponent : public Component
{
public:
    InputComponent();
    ~InputComponent();

    void SetInput(InputInfo* inpt) { this->input = input; }

    InputInfo* GetInput() { return input; }
    InputInfo* GetLastInput() { return lastInput; }

    bool isKeyPressed(KeyCode code)
    {
        if(input == nullptr)
            return false;

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
};