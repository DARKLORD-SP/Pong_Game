#include<SDL.h>

#pragma once
/// <summary>
/// RGB Color Storage
/// </summary>
struct Color
{
	Uint8 r, g, b;

	/// <summary>
	/// Defaults to black
	/// </summary>
	/// <returns></returns>
	Color();

	/// <summary>
	/// Sets the RGB Value
	/// </summary>
	/// <param name="_r">Red</param>
	/// <param name="_g">Green</param>
	/// <param name="_b">Blue</param>
	/// <returns></returns>
	Color(Uint8 _r, Uint8 _g, Uint8 _b);

	/// <summary>
	/// Copys the color value of c
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	Color(const Color& c);

	Color operator=(const Color& c);

};

