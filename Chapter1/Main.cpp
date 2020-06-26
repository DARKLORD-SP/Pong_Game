#include "Game.h"
#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"

int main(int argc, char** argv) {

	const int width = 1920;
	const int height = 1080;
	bool success = Game::GetInstance(width, height)->Initialize();

	//setting the Games FPS
	Game::GetInstance()->SetFPS(144);
	
	const int wallThickness = 15;
	Color wallColor(255, 100, 255);
	Renderer* topWall = new Wall(0, 0, width, wallThickness, height, wallColor,RenderType::Static, GameObject::Wall);
	Renderer* rightWall = new Wall(width - wallThickness, wallThickness, wallThickness, height, height, wallColor, RenderType::Static, GameObject::Wall);
	Renderer* bottomWall = new Wall(0, height - wallThickness, width, wallThickness, height, wallColor, RenderType::Static, GameObject::Wall);

	const int paddleHeight = 100;
	const int paddleWidth = 15;
	Color paddleColor(255, 255, 255);
	Paddle* paddle = new Paddle(10, (height / 2), paddleWidth, paddleHeight, height, 600.0f, paddleColor, GameObject::Paddle);
	Renderer* paddleRend = paddle;


	const int ballSize= 10;
	Color BallColor(255, 255, 0);
	Renderer* ball = new Ball(width / 2, height / 2, ballSize, ballSize, height, 400, BallColor, GameObject::Ball, paddle);

	if (success) 
	{
		Game::GetInstance()->RunLoop();
	}

	Game::GetInstance()->Shutdown();

	return 0;
}