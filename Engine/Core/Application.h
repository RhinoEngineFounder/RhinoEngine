#pragma once

#include "Super.h"
#include <SDL2/SDL.h>
#include <vector>

int main(int argc, char** argv);

typedef struct Arguments_RE
{
    int argc;
    char** args;

    const char* operator[](int index)
    {
        if(!args) return nullptr;
        return args[index];
    }
} Arguments;

typedef struct AppInfo_RE
{
    Arguments arguments;
    std::string workingDirectory;
    std::string name = "RhinoEngine game";
    bool enableGUI = false;
} AppInfo;

class Application
{
public:
    Application(AppInfo appinfo)
    {
        if(!currentLevel)
            currentLevel = defaultLevel();
            
        info = appinfo;
        master->Initiate(currentLevel, info.name.c_str());
        //currentLevel = levels[0];
    }

    ~Application() {}

    GameLayer* defaultLevel()
    {
        GameLayer* result = new GameLayer();
        Object* o = new Object(FVector(250, 250), FVector(100, 100));

        o->SetColor(Color(255, 255, 255, 1));
        result->color = Color(0, 0, 255, 1);
        result->AddObject(o);

        return result;
    }

    void run()
    {
        uint now = SDL_GetPerformanceCounter();
        uint last = 0;
        float deltaTime;

        while(isRunning)
        {
            deltaTime = Super::ComputeDeltaTime(last, now);
            if(Input::isKeyPressed(SDL_QUIT))
                isRunning = false;
            master->Update(deltaTime);
            if(Input::isKeyPressed(SDL_QUIT))
                isRunning = false;
            
            this->Update();
        }
    }

    void SwitchLevel(GameLayer* layer)
    {
        master->LoadLevel(layer);
    }

    virtual void Update() {}

    void end()
    {
        for(Object* e : currentLevel->GetEntites())
            e->End();
    }

protected:
    AppInfo info;
    Super* master = new Super();
    //std::vector<GameLayer*> levels;
    GameLayer *currentLevel;

    bool isRunning = true;
    friend int ::main(int argc, char** argv);
};

Application* CreateApp(Arguments);