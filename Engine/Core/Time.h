#pragma once
#include <SDL2/SDL.h>

class Time
{
public:
    Time();
    ~Time();

    void Update();
    float delta();
    float FramesPerSecond();
    float delay();

private:
    float start = 0;
    float end = 0;

    float deltaTime = 0;
    float fps = 0;
    float cap = 16.666f;
};