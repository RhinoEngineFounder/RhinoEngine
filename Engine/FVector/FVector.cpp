#include "FVector.h"

FVector::FVector() 
{
    this->x = 0;
    this->y = 0;
}

FVector::FVector(float x, float y)
{
    this->x = x;
    this->y = y;
}

FVector::~FVector() {}

FVector FVector::operator+ (const FVector &first) { return FVector(x + first.x, y + first.y); }
FVector FVector::operator- (const FVector &first) { return FVector(x - first.x, y - first.y); }

FVector FVector::operator+= (const FVector &first)
{
    this->x += first.x;
    this->y += first.y;
    return *this;
}

FVector FVector::operator-= (const FVector &first)
{
    this->x -= first.x;
    this->y -= first.y;
    return *this;
}

float FVector::distance(FVector a, FVector b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;

    return sqrt(dx * dx + dy * dy);
}

float FVector::angle(FVector a, FVector b) 
{ 
    float dot = a.x * b.x + b.y * b.x;
    float det = a.x * b.x - b.y * b.x;

    return atan2(det, dot); 
}

float FVector::lerp(float a, float b, float t) { return (a + t * (b - a)); }