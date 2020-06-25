#include "Paddle.h"

Paddle::~Paddle()
{
}

/// <summary>
/// Moves the Object.
/// </summary>
/// <param name="direction">Direction to move on</param>
/// <param name="speed">Speed of moving</param>
void Paddle::Move(Vector direction, const float& speed)
{
    position += direction * speed;
}

/// <summary>
/// Gets the Object Ready to be rendered
/// </summary>
/// <returns>coordinates of the object</returns>
SDL_Rect* Paddle::RenderRectangle()
{
    //Converting the Positions from center of the paddle to the top left of the paddle cause SDL_RECT takes positions in terms of top left corner.
    m_Paddle.x = (int)position.x - width / 2;
    m_Paddle.y = (int)position.y - height / 2;

    return &m_Paddle;
}
