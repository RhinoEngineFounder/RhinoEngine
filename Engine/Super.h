#pragma once

#include <iostream>
#include "Game/GameLayer.h"
#include "Renderer/Renderer.h"
#include "Components/InputComponent.h"
#include "Debug.h"

class Super
{
public:
    void Initiate(GameLayer*, const char*);
    void Run();

    void LoadLayer(GameLayer*);
    //static GameLayer* GetCurrentLayer();

    //void Test(GameLayer*);

private:
    GameLayer* currentLVL;
    Renderer* renderer;
};