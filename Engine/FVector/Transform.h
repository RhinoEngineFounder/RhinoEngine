#pragma once
#include "FVector.h"

class Transform
{
public:
    Transform() {}
    Transform(FVector l, FVector s) { location = l; scale = s; }
    ~Transform() {}

    /*void SetLocation(FVector l) { location = l; }
    void SetScale(FVector s)    { scale = s; }

    FVector GetLocation() { return location; }
    FVector GetScale()    { return scale; }*/

    FVector location;
    FVector scale;

private:
    // FVector rotation;
};