#include "Super.h"

void Super::Initiate(GameLayer *layer, const char *gameName) 
{
    std::ios::sync_with_stdio(false);
    currentLVL = layer;
    renderer = new Renderer(gameName, 640, 480);
    renderer->InitRenderer(currentLVL->color);

    for (Object *e : currentLVL->GetEntites())
      e->Awake();
}

void Super::Update(float deltaTime) 
{
    for (Object *e : currentLVL->GetEntites()) 
    {
        e->Tick(deltaTime);
        renderer->RenderObject(e);
    }

    renderer->UpdateScreen();
}

void Super::LoadLevel(GameLayer* layer) 
{
    currentLVL = layer;
    renderer->ChangeColor(layer->color);

    for(Object* e : currentLVL->GetEntites())
        e->Awake();
}