#pragma once
#include "../FVector/FVector.h"

class Camera
{
public:
    Camera()  {}
    Camera(FVector l) { position = l; }
    ~Camera() {}

    FVector position;
};