#pragma once
#include "../FVector/FVector.h"

class Camera
{
public:
    Camera() 
    {
        xBounda = 0;
        xBoundb = 250;
        yBounda = 0;
        yBoundb = 250;
    }

    Camera(float a, float b, float c, float d) 
    { 
        xBounda = a;
        xBoundb = b;
        yBounda = c;
        yBoundb = d;
    }
    ~Camera() {}

    float xBounda, xBoundb;
    float yBounda, yBoundb;
    FVector location;
};