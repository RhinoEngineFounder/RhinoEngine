#include "Engine/RhinoCore.h"
#include "Player.h"

class TestApp : public Application
{
public:
    TestApp(const AppInfo& info)
        : Application(info) 
    {
        GameLayer* demoLayer = new GameLayer();
        demoLayer->color = Color(0,0,255,1);
        demoLayer->AddObject(new Player());

        SwitchLevel(demoLayer);
    }

    void Update() override 
    {

    }
};

Application* CreateApp(Arguments args)
{
    AppInfo info;
    info.arguments = args;
    info.name = "Demo Game";

    return new TestApp(info);
}