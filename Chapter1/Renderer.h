#include<SDL.h>
#include "Color.h"

#pragma once

enum class RenderType { Static, Dynamic };

class Renderer
{
public:
	Renderer();
	Renderer(Renderer* obj, RenderType _typeOfRenderer, Color& _color);
	~Renderer();

	/// <summary>
	/// Makes the object Ready to Get Rendered.
	/// </summary>
	/// <returns>Updated Co-ordinate of the object</returns>
	virtual SDL_Rect* RenderRectangle() = 0;

private:
	Renderer* currentRenderObjPtr;
	RenderType currentRenderType;

public:
	Color* m_color;
};
