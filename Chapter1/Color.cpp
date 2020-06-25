#include "Color.h"

Color::Color()
{
	r = 0;
	g = 0;
	b = 0;
}

Color::Color(Uint8 _r, Uint8 _g, Uint8 _b)
{
	r = _r;
	g = _g;
	b = _b;
}

Color::Color(const Color& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
}

Color Color::operator=(const Color& c)
{
	r = c.r;
	g = c.g;
	b = c.b;

	return *this;
}
