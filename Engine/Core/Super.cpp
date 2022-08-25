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

void Super::Update(Time &time)
{
    time.Update();

    for (Object *e : currentLVL->GetEntites()) 
    {
        e->Tick(time.delta());
        //renderer->RenderObject(e, time);
    }

    renderer->RenderObjects(currentLVL->GetEntites(), time);
}

void Super::LoadLevel(GameLayer* layer) 
{
    currentLVL = layer;
    renderer->ChangeColor(layer->color);

    for(Object* e : currentLVL->GetEntites())
        e->Awake();
}