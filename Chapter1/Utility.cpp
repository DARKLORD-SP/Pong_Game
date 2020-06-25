#include "Utility.h"

float Utility::Lerp(const float& min, const float& max, const float& t)
{
	return ( (max - min) * t )+ t;
}
