#include "Renderer.h"

Renderer::Renderer(const char *name, int w, int h)
{
    if (name == NULL || w == 0 || h == 0)
        std::cerr << "Invalid Parameters for render initialization!";

    this->m_WindowName = name;
    this->m_ScreenHeight = h;
    this->m_ScreenWidth = w;
}

Renderer::~Renderer()
{
    SDL_FreeSurface(this->m_Surface);
    SDL_DestroyRenderer(this->m_Renderer);
    SDL_DestroyWindow(this->m_Window);
    SDL_Quit();
}

void Renderer::InitRenderer(Color c)//, Camera *cam)
{
    // Creating Window and Renderer
    this->m_Window = SDL_CreateWindow(this->m_WindowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_ScreenWidth, m_ScreenHeight, SDL_WINDOW_SHOWN);
    this->m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
    this->m_Surface = SDL_GetWindowSurface(m_Window);
    //this->m_Camera = cam;

    // Error checking
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cerr << "Failed initializing Rendering Engine! (SDL Init failed)\n";

    if (!m_Window)
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

void Renderer::RenderObject(Object *entity)
{
    SDL_RenderClear(m_Renderer);
    //if (entity->GetObjectLocation().x <= m_Camera->position.x || entity->GetObjectLocation().x >= m_Camera->position.x || entity->GetObjectLocation().y <= m_Camera->position.y || entity->GetObjectLocation().y >= m_Camera->position.y)
    //    return;

    SDL_SetRenderDrawColor(m_Renderer,
                           entity->GetColor().r,
                           entity->GetColor().g,
                           entity->GetColor().b,
                           entity->GetColor().a);
    SDL_Rect rect = Transform_To_Rect(entity->GetObjectTransform());

    switch (entity->GetShape())
    {
    case UNRENDERED:
        break;

    case RECTANGLE:
        SDL_RenderDrawRect(m_Renderer, &rect);
        break;

    case CIRCLE:
        DrawCircle(entity->GetObjectLocation().x + (entity->GetObjectScale().x / 2), entity->GetObjectLocation().y + (entity->GetObjectScale().y / 2), entity->GetObjectScale().x);
        break;

    case TRIANGLE:
        // SDL_RenderDrawLine();
        break;

    default:
        break;
    }

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

void Renderer::DrawCircle(int centreX, int centreY, int radius)
{
    const int diameter = (radius * 2);

    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    while (x >= y)
    {
        // Each of these function calls renders an octant of the circle
        SDL_RenderDrawPoint(m_Renderer, centreX + x, centreY - y);
        SDL_RenderDrawPoint(m_Renderer, centreX + x, centreY + y);
        SDL_RenderDrawPoint(m_Renderer, centreX - x, centreY - y);
        SDL_RenderDrawPoint(m_Renderer, centreX - x, centreY + y);
        SDL_RenderDrawPoint(m_Renderer, centreX + y, centreY - x);
        SDL_RenderDrawPoint(m_Renderer, centreX + y, centreY + x);
        SDL_RenderDrawPoint(m_Renderer, centreX - y, centreY - x);
        SDL_RenderDrawPoint(m_Renderer, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}