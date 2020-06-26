#include"GameObject.h"
#include <list>

#pragma once

class BoxCollider
{

public:
	GameObject whatAmI;	
	static std::list<BoxCollider*> m_AllTheColliders;
	float xPos;
	float yPos;
	int width;
	int height;
	int windowHeight;

public:
	BoxCollider(float& xP, float& yP, int& _width, int& _height, int _windHeight, GameObject& _whatAmI, BoxCollider* obj);
	~BoxCollider();

	virtual bool CaculateCollisions() = 0;

private:
	BoxCollider();
	BoxCollider(const BoxCollider& other) = delete;

};

