#include "BoxCollider.h"
#include <iostream>

std::list<BoxCollider*> BoxCollider::m_AllTheColliders;

BoxCollider::BoxCollider(float& xP, float& yP, int& _width, int& _height, int _windHeight, GameObject& _whatAmI, BoxCollider* obj)
{
	whatAmI = _whatAmI;
	
	xPos = xP;
	yPos = yP;
	width = _width;
	height = _height;

	windowHeight = _windHeight;

	m_AllTheColliders.push_front(obj);

	std::cout <<" \n BOX COLLIDER ADDED: " << "X POS: " << xPos << ", Y pos: " << yPos << "\n Wdith = " << width << " Height = " << height << std::endl;
}

BoxCollider::~BoxCollider() 
{
}
