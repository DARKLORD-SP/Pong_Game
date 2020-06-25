#include "Renderer.h"
#include "Game.h"

Renderer::Renderer()
{
    currentRenderObjPtr = nullptr;
    currentRenderType = RenderType::Dynamic;
    m_color = nullptr;
}

Renderer::Renderer(Renderer* obj, RenderType _typeOfRenderer, Color& _color)
{
    currentRenderObjPtr = obj;
    currentRenderType = _typeOfRenderer;
    m_color = &_color;

    if (_typeOfRenderer == RenderType::Static)
        Game::GetInstance()->AddStaticRenderObjects(obj);
    else
        Game::GetInstance()->AddDynamicRenderObjects(obj);
}

Renderer::~Renderer()
{
    if (currentRenderType == RenderType::Static)
        Game::GetInstance()->RemoveStaticRenderObjects(currentRenderObjPtr);
    else
        Game::GetInstance()->RemoveDynamicRenderObjects(currentRenderObjPtr);

    delete currentRenderObjPtr;
    delete m_color;
}

SDL_Rect* Renderer::RenderRectangle()
{
    return nullptr;
}
