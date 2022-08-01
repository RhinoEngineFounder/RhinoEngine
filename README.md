# RhinoEngine
## Why I want to make a game engine

Simple 2D Game engine, made by a 12 year old student in his freetime.

I decided to write a Simple 2D game engine in C++ using SDL to make small games and as
practice to improve my coding skills. 

## How to make a simple game

You can just code your own simple Character, by including the Engine/Object/Object.h file
in your Class, and copy this bit of Code:
```
class YouCharacterName : public Object
{
public:
    YourCharacterName();
    ~YourCharacterName();
  
    virtual void Awake() override;
    virtual void Tick(float deltaTime, InputInfo* input) override;
}
```
Then, you need a main file. To get everything runnin' you need to include Engine/Game/GameLayer.h.
This class is like a level or a scene, where every entity and the background color is stored.
Then you need to include the Core of the Engine: Engine/Super.h
First, you need to create a Level in your main function, and bind your character to it,
and then initialize the engine with your level.
```
int main()
{
    GameLayer* demoLayer = new GameLayer();    // Create a new Scene/Level
    demoLayer->color = Color(3, 128, 255, 1);  // Set your background color.
    
    YourCharacterName* character = new YourCharacterName();
    demoLayer->AddObject(character);
    
    Super* gameSuper;
    gameSuper.Initiate(demoLayer, "Demo game made with RhinoEngine");
    gameSuper.Run();
    
    return EXIT_SUCCESS;
}
```
If you compile everything you should see a window with blue background
and a box, you can control, if you do something like this in your character:
```
void YourCharacterName::Tick(float deltaTime, InputInfo* input)
{
    if(input->key.keysym.sym == SDLK_d)
        transform.location.x += 10;
        
    if(input->key.keysym.sym == SDLK_a)
        transform.location.x -= 10;
}
```
## How to compile your project

To compile your little game, just use the Makefile.
To use it, just type: 
```
make MAINFILE=main.cpp NAME=game Run
```
in a cmd.

## Social Media

With this you should be able to controll your character and move it to the left and right.
I'll continue working on the input system, and maybe stream 
my workflow on twitch at https://www.twitch.tv/theenderpod93

If you want to listen to the same music as I do when I code,
here is the link to my playlist: https://music.youtube.com/playlist?list=PLGYcHPtvAljUIQ_AX8MhWAoznyaK3N44K
