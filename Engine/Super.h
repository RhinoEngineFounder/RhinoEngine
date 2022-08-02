#pragma once

#include <iostream>
#include <unistd.h>
#include "Game/GameLayer.h"
#include "Renderer/Renderer.h"
#include "Debug.h"

class Super
{
public:
    void Initiate(GameLayer*, const char*);
    void Run();

    void LoadLayer(GameLayer*);

private:
    inline float ComputeDeltaTime(uint last, uint now)
    {
        last = now;
        now = SDL_GetTicks();
        return (float)((now - last) *1000 / (float)SDL_GetPerformanceFrequency());
    }

    GameLayer* currentLVL;
    Renderer* renderer;
};