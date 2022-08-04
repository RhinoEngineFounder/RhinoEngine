#include "Super.h"

void Super::Initiate(GameLayer* layer, const char* gameName) 
{
    std::ios::sync_with_stdio(false);
    currentLVL = layer;
    renderer = new Renderer(gameName, 640, 480);
    renderer->InitRenderer(currentLVL->color);//, currentLVL->cam);
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
    
    while(isRunning)
    {
        deltaTime = ComputeDeltaTime(last, now);

        SDL_Event input;
        while(SDL_PollEvent(&input))
        {
            if(input.type == SDL_QUIT) isRunning = false;
        }

        const Uint8* state = SDL_GetKeyboardState(nullptr);
        for(Object* e : currentLVL->GetEntites())
        {
            e->Tick(deltaTime, state);
            renderer->RenderObject(e);
        }

        renderer->UpdateScreen();
    }

    for(Object *e : currentLVL->GetEntites())
    {
        e->End();
    } 
}