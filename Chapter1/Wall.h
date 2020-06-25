#include "Renderer.h"

#pragma once

class Wall : public Renderer
{
public:
	Wall(int xP, int yP, int _width, int _height, Color& _color, RenderType typeOfObject) : Renderer(this, typeOfObject, _color)
	{		
		x = xP;
		y = yP;
		width = _width;
		height = _height;	
		
		//setting the rect struct to 0s
		m_wall.x = 0;
		m_wall.y = 0;
		m_wall.w = 0;
		m_wall.h = 0;
	}

	~Wall() 
	{

	}

	SDL_Rect* Renderer::RenderRectangle() override 
	{	
		m_wall.x = x;
		m_wall.y = y;
		m_wall.w = width;
		m_wall.h = height;

		return &m_wall;

	}

	const int GetX();
	const int GetY();

	const int GetWidth();
	const int GetHeight();

private:
	int x;
	int y;
	int width;
	int height;

	SDL_Rect m_wall;

};

