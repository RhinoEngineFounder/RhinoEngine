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

    // Input
    InputInfo input;

    while(isRunning)
    {
        last = now;
        now = SDL_GetTicks();
        deltaTime = (float)((now - last) *1000 / (float)SDL_GetPerformanceFrequency());

        while(SDL_PollEvent(&input) != 0)
        {
            if(input.type == SDL_QUIT) isRunning = false;
            for(Object* e : currentLVL->GetEntites())
            {
                if(e->GetComponent<InputComponent>())
                {
                    MESSAGE("Detected input component!")
                    e->GetComponent<InputComponent>()->SetInput(&input);
                }
            }
        }

        for(Object* e : currentLVL->GetEntites())
        {
            e->Tick(deltaTime);
            renderer->RenderObject(e);
        }

        renderer->UpdateScreen();
    }
}

//GameLayer* Super::GetCurrentLayer() { return currentLVL; }