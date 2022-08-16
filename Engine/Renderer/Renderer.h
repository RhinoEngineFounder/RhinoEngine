#pragma once
#include <SDL2/SDL.h>
#include <iostream>

#include "../Object/Object.h"
#include "../Material/Color.h"
#include "../Layer/Camera.h"
#include "../Core/Debug.h"

class Renderer
{
public:
    Renderer(const char* name, int w, int h);
    ~Renderer();

    void InitRenderer(Color);
    void RenderObject(Object*);
    inline void ChangeColor(Color c) { m_BC = c; }

    void UpdateScreen();

private:
    inline SDL_Rect Transform_To_Rect(Transform);
    void DrawCircle(int, int, int);
    void DrawTriangle(Object*);

    int m_ScreenWidth;
    int m_ScreenHeight;
    const char* m_WindowName;

    Color m_BC; // Background color
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    SDL_Surface* m_Surface;
    //Camera* m_Camera;
};