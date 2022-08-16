# RhinoEngine
Simple 2D Game engine, made by a 12 year old student in his freetime.
## Why I want to make a game engine

I decided to write a Simple 2D game engine in C++ using SDL to make small games and as
practice to improve my coding skills. 

## How to make a simple game

You can just code your own simple Character, by including the Engine/Object/Object.h, or the Engine/RhinoCore.h file
in your Class, and copy this bit of Code:
```
class YouCharacterName : public Object
{
public:
    YourCharacterName();
    ~YourCharacterName();
  
    virtual void Awake() override;
    virtual void Tick(float deltaTime, InputInfo* input) override;
    virtual void End() override;
}
```
Then, you need an Application class, and implement the CreateApp function that
returns an object of your application. First off, include the Engine/RhinoCore.h file,
and create a class, inheriting from a public Application:
```
class TestApp : public Application
{
public:
    TestApp(const AppInfo info&) 
	: Application(info)
    {
    	
    }

    void Update() override {  }
};

Application* CreateApp(Arguments args)
{
    AppInfo appInfo;
    appInfo.arguments = args;
    appInfo.name = "My Rhino Engine Game";

    return new TestApp(appInfo);
}
```
If you compile and run everything, you should see a box in the
center of the screen with a blue backround. But to add controls,
you need to create your own level. You have to do something like this in 
the constructor of your class:
```
GameLayer* demoLayer = new GameLayer();
demoLayer->color = Color(0,0,255,1);
demoLayer->AddObject(new Player());

SwitchLevel(demoLayer);
```
If you compile everything you should see a window with blue background
and a box, you can control, if you do something like this in your character:
```
void YourCharacterName::Tick(float deltaTime)
{
    if(Input::isKeyHeldDown(KeyCode_d) && !(transform.location.x >= 540)) // Check input and don't let your Player escape!
        transform.location.x += 0.1 * deltaTime; // Move your character!
        
    if(Input::isKeyHeldDown(KeyCode_a) && !(transform.location.x <= 0))
        transform.location.x -= 0.1;
}
```
## How to compile your project

To compile your little game, just use the Makefile.
To use it, just enter this in a console (Of course in the right directory): 
```
make MAINFILE=FileWithAppClass.cpp NAME=game Run
```

## Social Media

With this you should be able to controll your character and move it to the left and right.
I'll continue working on the input system, and maybe stream 
my workflow on twitch at https://www.twitch.tv/theenderpod93

If you want to listen to the same music as I do when I code,
here is the link to my playlist: https://music.youtube.com/playlist?list=PLGYcHPtvAljUIQ_AX8MhWAoznyaK3N44K

If you want annoying tweets, here is my twitter account: https://twitter.com/TheNerdRoom3
