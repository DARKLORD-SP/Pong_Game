#include "Vector.h"
#include "GameObject.h"

#pragma once

class Physics
{
	Physics() = delete;
	Physics(const Physics&) = delete;
	Physics operator=(const Physics&) = delete;

public:
	Physics(Physics* obj, GameObject type, float _speed);
	~Physics();

	/// <summary>
	/// Moves the Object.
	/// </summary>
	/// <param name="direction">Direction to move in.</param>
	/// <param name="speed">Speed of moving</param>
	virtual void Move(const float& speed) = 0;

	const GameObject& GetTypeOfObject();
	
	void SetDirection(Vector V);
	Vector GetDirection();

	float GetSpeed();
	void SetSpeed(const float& _speed);

	Vector GetVelocity();
	void SetVelocity(Vector v);

private:
	Physics* m_PhysicsObj;
	GameObject m_objectType;
	Vector m_direction;
	float speed;
	Vector m_velocity;
};

