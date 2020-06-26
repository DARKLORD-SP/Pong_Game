#include "Renderer.h"
#include "GameObject.h"
#include "BoxCollider.h"

#pragma once

class Wall : public Renderer, public BoxCollider
{
public:
	Wall(float xP, float yP, int _width, int _height, int _windHeight ,Color& _color, RenderType typeOfObject, GameObject type) : Renderer(this, typeOfObject, _color), BoxCollider(xP, yP, _width, _height, _windHeight, type, this)
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

	// Inherited via BoxCollider
	virtual bool CaculateCollisions() override;

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

