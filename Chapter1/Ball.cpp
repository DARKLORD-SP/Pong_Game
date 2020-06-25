#include "Ball.h"

Ball::~Ball()
{
}

/// <summary>
/// Moves the Object.
/// </summary>
/// <param name="speed">Speed of moving</param>
void Ball::Move( const float& speed)
{
    position += GetDirection() * speed;
}

/// <summary>
/// Gets the Object Ready to be rendered
/// </summary>
/// <returns>coordinates of the object</returns>
SDL_Rect* Ball::RenderRectangle()
{
    //Converting the Positions from center of the Ball to the top left of the ball cause SDL_RECT takes positions in terms of top left corner.
    m_Ball.x = (int)position.x - width / 2;
    m_Ball.y = (int)position.y - height / 2;

    return &m_Ball;
}
