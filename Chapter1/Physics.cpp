#include "Physics.h"
#include "Game.h"

Physics::Physics(Physics* obj, GameObject type, float _speed)
{
	Game::GetInstance()->AddPhysicsObject(obj);
	m_PhysicsObj = obj;
	m_objectType = type;
	speed = _speed;
}

Physics::~Physics()
{
	delete m_PhysicsObj;
}

const GameObject& Physics::GetTypeOfObject()
{
	return m_objectType;
}

void Physics::SetDirection(Vector V)
{
	m_direction.x = V.x;
	m_direction.y = V.y;
}

Vector Physics::GetDirection()
{
	return m_direction;
}

float Physics::GetSpeed()
{
	return speed;
}

void Physics::SetSpeed(const float& _speed)
{
	speed = _speed;
}

Vector Physics::GetVelocity()
{
	return m_velocity;
}

void Physics::SetVelocity(Vector v)
{
	m_velocity.x = v.x;
	m_velocity.y = v.y;
}
