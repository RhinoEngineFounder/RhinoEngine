#pragma once
#include "../FVector/Transform.h"
#include "../Components/InputComponent.h"
#include "../Material/Shape.h"
#include "../Material/Color.h"
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

    void SetObjectTransform(Transform);
    void SetObjectLocation(FVector);
    void SetObjectScale(FVector);
    void SetShape(Shape);
    void SetColor(Color);

    virtual void Awake() {}
    virtual void Tick(float deltaTime) {}
    // virtual void HandleInput(InputInfo*) {}

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

    inline void AddComponent(Component*);

protected:
    Transform transform;
    InputComponent* input;
    std::vector<Component*> components;

private:
    Shape shape;
    Color color;
};