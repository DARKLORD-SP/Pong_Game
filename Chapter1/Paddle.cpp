#include "Paddle.h"

Paddle::~Paddle()
{
}

/// <summary>
/// Moves the Object.
/// </summary>
/// <param name="speed">Speed of moving</param>
void Paddle::Move( const float& speed)
{
    position += GetDirection() * speed;

    CaculateCollisions();
}

/// <summary>
/// Calculates the Collisions
/// </summary>
/// <returns></returns>
bool Paddle::CaculateCollisions()
{
    bool collided = false;

    std::list<BoxCollider*>::iterator iter;

    for (iter = m_AllTheColliders.begin(); iter != m_AllTheColliders.end(); iter++) 
    {
        BoxCollider* collider = iter._Ptr->_Myval;
        
        //Checks for collision only if with walls
        if (collider->whatAmI == GameObject::Wall)
        {
            //Upper wall
            if ((int)collider->yPos == 0) {
                if ((int)(position.y - height / 2) <= (int)(collider->yPos + collider->height)) {
                    position.y = collider->yPos + collider->height + (height / 2);
                    collided = true;
                }
            }
            //bottom wall
            else if (collider->height < windowHeight) {
                if ((int)(position.y + height / 2) > (int)(windowHeight - collider->height)) {
                    position.y = collider->yPos - height / 2;
                    collided = true;
                }
            }
        }

    }    

    return collided;
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
