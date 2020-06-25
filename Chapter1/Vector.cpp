#include "Vector.h"

Vector::Vector()
{
	x = 0.0f;
	y = 0.0f;
}

Vector::Vector(float vx, float vy)
{
	x = vx;
	y = vy;
}

Vector::Vector(const Vector& vec)
{
	x = vec.x;
	y = vec.y;
}

const Vector& Vector::operator=(const Vector& vec)
{
	x = vec.x;
	y = vec.y;

	return *this;
}

Vector::~Vector()
{
}

const Vector& Vector::operator+(const Vector& V)
{
	x += V.x;
	y += V.y;

	return *this;
}

const Vector& Vector::operator-(const Vector& V)
{
	x -= V.x;
	y -= V.y;

	return *this;
}

const Vector& Vector::operator*(const float& S)
{
	x = x * S;
	y = y * S;

	return *this;
}

const Vector& Vector::operator+=(const Vector& v)
{
	x = x + v.x;
	y = y + v.y;

	return *this;
}

const Vector& Vector::operator-=(const Vector& v)
{
	x = x - v.x;
	y = y - v.y;

	return *this;
}

const Vector& Vector::operator*=(const float& S)
{
	x = x * S;
	y = y * S;

	return *this;
}

