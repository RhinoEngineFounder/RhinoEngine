#pragma once
typedef unsigned int uint;

class Color
{
public:
    Color() {}
    Color(uint r, uint g, uint b, uint a) 
    { 
        this->r = r;
        this->g = g; 
        this->b = b; 
        this->a = a;
    }
    
    ~Color() {}

    Uint8 r, g, b, a;
};