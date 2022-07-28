#include "Renderer.h"

Renderer::Renderer(const char* name, int w, int h)
{
    if(name == NULL || w == 0 || h == 0)
        std::cerr << "Invalid Parameters for render initialization!";
    
    this->m_WindowName   = name;
    this->m_ScreenHeight = h;
    this->m_ScreenWidth  = w;
}

Renderer::~Renderer()
{
    SDL_FreeSurface(this->m_Surface);
    SDL_DestroyRenderer(this->m_Renderer);
    SDL_DestroyWindow(this->m_Window);
    SDL_Quit();
}

void Renderer::InitRenderer(Color c)
{
    // Creating Window and Renderer
    this->m_Window = SDL_CreateWindow(this->m_WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_SHOWN);
    this->m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    this->m_Surface = SDL_GetWindowSurface(m_Window);
    
    // Error checking
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << "Failed initializing Rendering Engine! (SDL Init failed)\n";
    
    if(!m_Window)
        std::cerr << "Failed creating window!\n";
    
    // Set render draw color
    this->m_BC = c;
    SDL_SetRenderDrawColor(this->m_Renderer, 
                           c.r,
                           c.g,
                           c.b,
                           c.a);
    SDL_RenderClear(this->m_Renderer);
    SDL_RenderPresent(this->m_Renderer);
}

void Renderer::RenderObject(Object* entity) 
{   
    SDL_RenderClear(m_Renderer);
    SDL_SetRenderDrawColor(m_Renderer,
                           entity->GetColor().r,
                           entity->GetColor().g,
                           entity->GetColor().b,
                           entity->GetColor().a);
    SDL_Rect rect = Transform_To_Rect(entity->GetObjectTransform());
    
    if(entity->GetShape() == RECTANGLE)
        SDL_RenderDrawRect(m_Renderer, &rect);
    
    SDL_SetRenderDrawColor(m_Renderer, m_BC.r, m_BC.g, m_BC.b, m_BC.a);
    SDL_RenderPresent(m_Renderer);
}

void Renderer::UpdateScreen() { SDL_RenderPresent(this->m_Renderer); }

inline SDL_Rect Renderer::Transform_To_Rect(Transform transform)
{
    SDL_Rect result;
    result.x = transform.location.x;
    result.y = transform.location.y;
    result.w = transform.scale.x;
    result.h = transform.scale.y;
    
    return result;
}