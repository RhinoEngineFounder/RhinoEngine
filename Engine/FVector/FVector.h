#pragma once

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

    float x, y;
    static FVector ZeroVector();
};