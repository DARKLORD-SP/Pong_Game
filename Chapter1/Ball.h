#include"Renderer.h"
#include"Physics.h"
#include "Vector.h"
#include "GameObject.h"
#include "BoxCollider.h"
#include "Paddle.h"

#pragma once

class Ball : public Renderer, public Physics, public BoxCollider
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
	Ball(float xP, float yP, int _width, int _height, int _windHeight, float _speed, Color& color, GameObject type, const Paddle* paddle) : Renderer(this, RenderType::Dynamic, color), Physics(this, type, _speed), BoxCollider(xP, yP, _width, _height, _windHeight, type, this)
	{
		position.x = xP;
		position.y = yP;

		width = _width;
		height = _height;

		m_Ball.x = (int)position.x;
		m_Ball.y = (int)position.y;
		m_Ball.w = width;
		m_Ball.h = height;

		m_paddle = paddle;
	}

private:
	int width;
	int height;
	SDL_Rect m_Ball;
	const Paddle* m_paddle;

public:
	Vector position;
		
	// Inherited via Physics	
	virtual void Move(const float& speed) override;

	// Inherited via Renderer
	virtual SDL_Rect* RenderRectangle() override;

	// Inherited via BoxCollider
	virtual bool CaculateCollisions() override;

private:

	bool ProcessCollisionAgainstWalls(BoxCollider* collider);

};

