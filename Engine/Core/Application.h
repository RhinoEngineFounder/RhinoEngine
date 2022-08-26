#pragma once

#include "Super.h"
#include "../Layer/Plugin.h"
#include <SDL2/SDL.h>
#include <vector>

int main(int argc, char** argv);

struct Arguments
{
    int argc;
    char** args;

    const char* operator[](int index)
    {
        if(!args) return nullptr;
        return args[index];
    }
};

struct AppInfo
{
    Arguments arguments;
    std::string workingDirectory;
    std::string name = "RhinoEngine game";
    bool enableGUI = false;
};

class Application
{
public:
    Application(AppInfo appinfo);
    ~Application();

    GameLayer* defaultLevel();

    void run();
    void end();
    void AddPlugin(Plugin* plug);
    void RemovePlugin(Plugin* plug);

    inline void SwitchLevel(GameLayer* layer) { master->LoadLevel(layer); }
    inline std::vector<Plugin*> GetPlugins() { return m_plugins; }

protected:
    AppInfo info;
    Super* master = new Super();
    Time time;
    GameLayer *currentLevel;

private:
    std::vector<Plugin*> m_plugins;

    bool isRunning = true;
    friend int ::main(int argc, char** argv);
};

Application* CreateApp(Arguments);