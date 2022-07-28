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

FVector::~FVector() {}