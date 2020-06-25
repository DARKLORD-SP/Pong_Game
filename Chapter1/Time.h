#include <SDL.h>

#pragma once

/// <summary>
/// Game Time Class
/// </summary>
class Time
{
private:
	static float deltaTime;
	static Uint32 previousFrameTime;
	static float FPS;

public:
	/// <summary>
	/// Gets the current Fps.
	/// note:- -1 referes to Unlimited FPS.
	/// </summary>
	/// <returns>Number of Fps</returns>
	static float GetFPS();

	/// <summary>
	/// set the amount of Frames to render per second.
	///note:-For Unlimited Frames Pass -1.
	/// </summary>
	/// <param name="framesPerSecond"></param>
	static void SetFPS(float framesPerSecond = 1);

	static float GetDeltaTime();

	static void UpdateDeltaTime();

private :
	static float Clamp(float value, float min, float max);

};

