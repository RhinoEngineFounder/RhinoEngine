#include "Super.h"

void Super::Initiate(GameLayer* layer, const char* gameName) 
{
    std::ios::sync_with_stdio(false);
    currentLVL = layer;
    renderer = new Renderer(gameName, 640, 480);
    renderer->InitRenderer(currentLVL->color);
}

void Super::Run()
{
    for(Object* e : currentLVL->GetEntites())
        e->Awake();

    // Performance
    uint now = SDL_GetPerformanceCounter();
    uint last = 0;
    float deltaTime;
    bool isRunning = true;

    InputInfo input;
    
    while(isRunning)
    {
        deltaTime = ComputeDeltaTime(last, now);

        if(!SDL_PollEvent(&input))
        {
            for(Object* e : currentLVL->GetEntites())
            {
                e->Tick(deltaTime, &input);
                usleep(10000);
                renderer->RenderObject(e);
            }
        }

        while(SDL_PollEvent(&input))
        {
            if(input.type == SDL_QUIT) isRunning = false;
            
            for(Object* e : currentLVL->GetEntites())
            {
                e->Tick(deltaTime, &input);
                renderer->RenderObject(e);
            }
        }

        renderer->UpdateScreen();
    }
}