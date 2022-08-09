#pragma once
#include <math.h>
#include <SDL2/SDL.h>

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

    inline SDL_FPoint ToSDL_FPoint()
    {
        SDL_FPoint result;
        result.x = this->x;
        result.y = this->y;
        
        return result;
    }

    float x, y;
    static FVector ZeroVector();
};