#pragma once
#include "../FVector/Transform.h"
#include "../Components/InputComponent.h"
#include "../Graphics/Shape.h"
//#include "../Graphics/Texture.h"
#include "../Graphics/Color.h"
#include "../Components/Component.h"
#include <vector>

class Object
{
public:
    Object();
    Object(FVector l, FVector s);
    ~Object();

    Transform GetObjectTransform();
    FVector GetObjectLocation();
    FVector GetObjectScale();
    Shape GetShape();
    Color GetColor();
    //Texture* GetTexture();

    void SetObjectTransform(Transform);
    void SetObjectLocation(FVector);
    void SetObjectScale(FVector);
    void SetShape(Shape);
    void SetColor(Color);
    //void SetTexture(Texture*);

    virtual void Awake() {}
    virtual void Tick(float deltaTime) {}
    virtual void End() {}

    template <class CompType>
    CompType *GetComponent()
    {
        CompType *result = nullptr;
        for (Component *currComp : components)
        {
            result = static_cast<CompType*>(currComp);
            if (result)
                break;
        }
        return result;
    }

    inline void AddComponent(Component* c) { components.push_back(c); }

protected:
    Transform transform;
    std::vector<Component*> components;

private:
    Shape shape;
    Color color;
    //Texture* texture;
};