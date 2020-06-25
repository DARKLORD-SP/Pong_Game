#include "Time.h"
#include <iostream>

float Time::deltaTime = 0;
Uint32 Time::previousFrameTime = 0;
float Time::FPS = -1;

float Time::GetFPS()
{
    return FPS;
}

void Time::SetFPS(float framesPerSecond)
{
    FPS = framesPerSecond;
}

float Time::GetDeltaTime()
{
    return deltaTime;
}

void Time::UpdateDeltaTime()
{
    //If FPS is provided then make the delta time dependant on FPS.
    if (FPS != -1) {        
        if ((SDL_GetTicks() - previousFrameTime) > (1000.0f / FPS))
        {
            deltaTime = (SDL_GetTicks() - previousFrameTime) / 1000.0f;
            previousFrameTime = SDL_GetTicks();
            deltaTime = Clamp(deltaTime, 0, 1);
        }
        else
            deltaTime = 0;

    }
    //unlimited FPS
    else {
        deltaTime = (SDL_GetTicks() - previousFrameTime) / 1000.0f;
        previousFrameTime = SDL_GetTicks();
        deltaTime = Clamp(deltaTime, 0, 1);
    }

}

float Time::Clamp(float value, float min, float max) {
    if (value < min)
        value = min;
    else if (value > max)
        value = max;

    return value;
}