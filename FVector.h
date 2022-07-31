#pragma once
#include <math.h>

class FVector
{
public:
    FVector();
    FVector(float x, float y);
    ~FVector();

    FVector operator+ (const FVector &first);
    FVector operator- (const FVector &first);
    FVector operator+= (const FVector &first);
    FVector operator-= (const FVector &first);

    float distance(FVector a, FVector b);
    float angle(FVector a, FVector b);
    float lerp(float, float, float);

    float x, y;
    static FVector ZeroVector();
};