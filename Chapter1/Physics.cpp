#include "Physics.h"
#include "Game.h"

Physics::Physics(Physics* obj)
{
	Game::GetInstance()->AddPhysicsObject(obj);
	m_PhysicsObj = obj;
}

Physics::~Physics()
{
	delete m_PhysicsObj;
}
