#include "Time.h"

Time::Time() {}
Time::~Time() {}

void Time::Update()
{
    end = start;
    start = SDL_GetTicks();

    deltaTime = ((start - end) * 1000 / (float)SDL_GetPerformanceFrequency());
    fps = (end - start) / SDL_GetPerformanceFrequency() / 1.0f;
}

float Time::delta() { return deltaTime; }
float Time::FramesPerSecond() { return fps; }
float Time::delay()
{
    return floor(cap - deltaTime);
}