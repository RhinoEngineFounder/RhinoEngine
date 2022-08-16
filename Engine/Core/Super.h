#pragma once

#include <iostream>
#include <unistd.h>
#include "../Layer/GameLayer.h"
#include "../Renderer/Renderer.h"
#include "Debug.h"

#define UPDATE_DELAY 10000

class Super
{
public:
    void Initiate(GameLayer*, const char*);
    void Update(float);

    void LoadLevel(GameLayer*);

    static inline float ComputeDeltaTime(uint last, uint now)
    {
        last = now;
        now = SDL_GetTicks();
        return (float)((now - last) *1000 / (float)SDL_GetPerformanceFrequency());
    }

private:
    GameLayer* currentLVL;
    Renderer* renderer;
};