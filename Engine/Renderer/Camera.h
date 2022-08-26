#pragma once
#include "../FVector/FVector.h"

class Camera
{
public:
    Camera()
    {
        location.x = 0;
        location.y = 0;
    }
    ~Camera() {}

    FVector location;
};