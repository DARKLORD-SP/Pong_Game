#include"Renderer.h"
#include"Physics.h"
#include "Vector.h"
#include "GameObject.h"

#pragma once

class Ball : public Renderer, public Physics
{
	Ball() = delete;

	Ball(const Ball& p) = delete;

	~Ball();

public:
	/// <summary>
	/// Intializes the ball Object
	/// </summary>
	/// <param name="xP">Intial X positon</param>
	/// <param name="yP">Intial Y Position</param>
	/// <param name="_width">width of the ball</param>
	/// <param name="_height">Height of the ball</param>
	/// <param name="color">Color of the ball</param>
	/// <returns></returns>
	Ball(float xP, float yP, int _width, int _height, float _speed, Color& color, GameObject type) : Renderer(this, RenderType::Dynamic, color), Physics(this, type, _speed)
	{
		position.x = xP;
		position.y = yP;

		width = _width;
		height = _height;

		m_Ball.x = (int)position.x;
		m_Ball.y = (int)position.y;
		m_Ball.w = width;
		m_Ball.h = height;
	}

private:
	int width;
	int height;
	SDL_Rect m_Ball;

public:
	Vector position;
		
	// Inherited via Physics	
	virtual void Move(const float& speed) override;

	// Inherited via Renderer
	virtual SDL_Rect* RenderRectangle() override;

};

