#pragma once
#include <SDL2/SDL.h>
#include <iostream>

#include "../Object/Object.h"
#include "../Material/Color.h"
#include "../Game/Camera.h"

class Renderer
{
public:
    Renderer(const char* name, int w, int h);
    ~Renderer();

    void InitRenderer(Color);
    void RenderObject(Object*);

    void UpdateScreen();

private:
    inline SDL_Rect Transform_To_Rect(Transform);
    void DrawCircle(int, int, int);

    int m_ScreenWidth;
    int m_ScreenHeight;
    const char* m_WindowName;

    Color m_BC; // Background color
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    SDL_Surface* m_Surface;
    //Camera* m_Camera;
};