#include "Vector.h"
#include "Renderer.h"
#include "Physics.h"

#pragma once

/// <summary>
/// Paddle Object class
/// </summary>
class Paddle : public Renderer, public Physics
{

	Paddle() = delete;
	
	Paddle(const Paddle& p) = delete;

	~Paddle();

public:
	/// <summary>
	/// Initialzing the Paddle object.
	/// </summary>
	/// <param name="xP">Intial X Position</param>
	/// <param name="yP">Intial Y position</param>
	/// <param name="_width">Paddle Width</param>
	/// <param name="_height">paddle Height</param>
	/// <param name="color">Paddle Color</param>
	/// <returns></returns>
	Paddle(float xP, float yP, int _width, int _height, Color& color) : Renderer(this, RenderType::Dynamic, color), Physics(this)
	{
		position.x = xP;
		position.y = yP;

		width = _width;
		height = _height;

		m_Paddle.x = (int)position.x;
		m_Paddle.y = (int)position.y;
		m_Paddle.w = width;
		m_Paddle.h = height;
	}

public:
	//inherited via Physics
	virtual void Move(Vector direction, const float& speed) override;

	// Inherited via Renderer
	virtual SDL_Rect* RenderRectangle() override;

private:
	int width;
	int height;
	SDL_Rect m_Paddle;

public:
	Vector position;

};

