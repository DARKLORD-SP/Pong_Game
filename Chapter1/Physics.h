#include "Vector.h"

#pragma once

class Physics
{
	Physics() = delete;
	Physics(const Physics&) = delete;
	Physics operator=(const Physics&) = delete;

public:
	Physics(Physics* obj);
	~Physics();

	/// <summary>
	/// Moves the Object.
	/// </summary>
	/// <param name="direction">Direction to move in.</param>
	/// <param name="speed">Speed of moving</param>
	virtual void Move(Vector direction, const float& speed) = 0;

private:
	Physics* m_PhysicsObj;
};

