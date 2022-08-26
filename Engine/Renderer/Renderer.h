#pragma once
#include <SDL2/SDL.h>
#include <iostream>

#include "../Object/Object.h"
#include "../Graphics/Color.h"
#include "Camera.h"
#include "../Core/Debug.h"
#include "../Core/Time.h"

class Renderer
{
public:
    Renderer(const char* name, int w, int h);
    ~Renderer();

    void InitRenderer(Color);
    void RenderObject(Object*, Time);
    void RenderObjects(std::vector<Object*>, Time&);
    inline void ChangeColor(Color c) { background = c; }

    void Present();

private:
    inline SDL_Rect Transform_To_Rect(Transform);
    void DrawCircle(int, int, int);
    void DrawTriangle(Object*);

    int m_ScreenWidth;
    int m_ScreenHeight;
    const char* m_WindowName;

    Color background; // Background color
    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    SDL_Surface* m_Surface;
};