#include "Ball.h"
#include <iostream>

Ball::~Ball()
{
    Renderer::~Renderer();
    Physics::~Physics();
    BoxCollider::~BoxCollider();
}

/// <summary>
/// Moves the Object.
/// </summary>
/// <param name="speed">Speed of moving</param>
void Ball::Move( const float& speed)
{
    position += GetDirection() * speed;

    CaculateCollisions();
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

bool Ball::CaculateCollisions()
{
    bool collided = false;

    std::list<BoxCollider*>::iterator iter;

    for (iter = m_AllTheColliders.begin(); iter != m_AllTheColliders.end(); iter++)
    {
        BoxCollider* collider = iter._Ptr->_Myval;

        //Ball Collided with the wall
        if (collider->whatAmI == GameObject::Wall) 
        {
            collided = ProcessCollisionAgainstWalls(collider);

            //Collision Against Paddle
            float diff = position.y - m_paddle->position.y;
            if (diff < 0)
                diff = diff * -1;

            //if the difference is less than or equal to the height of paddle than the ball is in the range of paddle height.
            if (diff <= m_paddle->height / 2.0f && position.x <= (m_paddle->position.x + m_paddle->width) && GetDirection().x < 0) 
            {
                Vector dir = GetDirection();
                dir.x *= -1;

                SetDirection(dir);
            }

        }

    }

    return collided;
}

bool Ball::ProcessCollisionAgainstWalls(BoxCollider* collider)
{
    bool collided = false;

    //ball is moving up
    if (GetDirection().y < 0) {
        //Upper wall
        if ((int)collider->yPos == 0)
        {
            if ((int)(position.y - height / 2) < (int)(collider->yPos + collider->height))
            {
                Vector newDir = GetDirection();
                newDir.y *= -1;
                SetDirection(newDir);
                collided = true;
            }
        }
    }
    //ball is moving down
    else if (GetDirection().y > 0) {

        //bottom wall
        if ((int)collider->yPos > collider->height && collider->yPos >= windowHeight - collider->height)
        {
            if ((int)(position.y + height / 2) > (int)(windowHeight - collider->height))
            {
                Vector newDir = GetDirection();
                newDir.y *= -1;
                SetDirection(newDir);
                collided = true;
            }
        }
    }
    //ball is moving right
    if (GetDirection().x > 0) {
        //right wall
        if ((int)collider->xPos > 0) {
            if ((int)(position.x + width / 2) > collider->xPos)
            {
                Vector newDir = GetDirection();
                newDir.x *= -1;
                SetDirection(newDir);
                collided = true;
            }
        }
    }

    return collided;
}
