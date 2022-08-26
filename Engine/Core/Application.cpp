#include "Application.h"

Application::Application(AppInfo appinfo) 
{
    if (!currentLevel)
        currentLevel = defaultLevel();

    info = appinfo;
    master->Initiate(currentLevel, info.name.c_str());
}

Application::~Application() {}

GameLayer* Application::defaultLevel()
{
    GameLayer* result = new GameLayer();
    Object* o = new Object(FVector(250, 250), FVector(100, 100));

    o->SetColor(Color(255, 255, 255, 1));
    result->color = Color(0, 0, 255, 1);
    result->AddObject(o);

    return result;
}

void Application::run()
{
    while(isRunning)
    {
        time.Update();
        
        if(Input::isKeyPressed(SDL_QUIT))
            isRunning = false;
            
        master->Update(time);
        for(Plugin *p : m_plugins)
            p->Update(time.delta());
    }
}

void Application::end()
{
    for(Object* e : currentLevel->GetEntites())
        e->End();

    for(Plugin* plug : m_plugins)
        plug->End();
}

void Application::AddPlugin(Plugin *plug)
{
    m_plugins.push_back(plug);
    plug->Awake();
}

void Application::RemovePlugin(Plugin* plug)
{
    if(!plug) return;
    auto itr = std::find(m_plugins.begin(), m_plugins.end(), plug);
    if(itr == m_plugins.end()) return;
    plug->End();
    m_plugins.erase(itr);
}

