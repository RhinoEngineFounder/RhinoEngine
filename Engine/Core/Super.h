#pragma once

#include <iostream>
#include <unistd.h>
#include "../Layer/GameLayer.h"
#include "../Renderer/Renderer.h"
#include "Time.h"
#include "Debug.h"

class Super
{
public:
    void Initiate(GameLayer*, const char*);
    void Update(Time&);
    void LoadLevel(GameLayer*);

    //inline VRenderer* GetRenderer() { return renderer; }

private:
    GameLayer* currentLVL;
    Renderer* renderer;
};