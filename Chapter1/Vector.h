#pragma once
struct Vector
{
	float x;
	float y;

	Vector();

	Vector(float vx, float vy);

	Vector(const Vector& vec);

	const Vector& operator =(const Vector& vec);

	~Vector();

	const Vector& operator+(const Vector& V);

	const Vector& operator-(const Vector& V);

	const Vector& operator*(const float& S);

	const Vector& operator+=(const Vector& v);
	
	const Vector& operator-=(const Vector& v);

	const Vector& operator*= (const float& S);

};

