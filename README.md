# RhinoEngine
Simple 2D Game engine, made by a 12 year old student in his freetime.

I decided to write a Simple 2D game engine in C++ using SDL to make small games and as
practice to improve my coding skills. 

The current version does not compile, but I'm working on a solution for that. The problem is the InputComponent.h file,
but in the near future, you can just code your own simple Character, by including the Engine/Object/Object.h file
in your Class, and copy this bit of Code:

class YouCharacterName : public Object
{
public:
    YourCharacterName();
    ~YourCharacterName();
  
    virtual void Awake() override;
    virtual void Tick(float deltaTime) override;
}

Then, you need a main file. To get everything runnin' you need to include Engine/Game/GameLayer.h.
This class is like a level or a scene, where every entity and the background color are stored.
Then you need to include the Core of the Engine: Engine/Super.h
First, you need to create a Level in your main function, and bind your character to it,
and then initialize the engine with your level.

int main()
{
    GameLayer* demoLayer = new GameLayer();    // Create a new Scene/Level
    demoLayer->color = Color(3, 128, 255, 1);  // Set your background color.
    
    YourCharacterName* character = new YourCharacterName();
    demoLayer->AddObject(character);
    
    Super* gameSuper;
    gameSuper.Initiate(demoLayer, "Demo game made with RhinoEngine");
    gameSuper.Run();
}

If you compile everything (which doesn't work currently) you should see a window with blue background
and a box, you can control as soon as I fix the InputComponent.
