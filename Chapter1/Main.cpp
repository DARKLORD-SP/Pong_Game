#include "Game.h"
#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"

int main(int argc, char** argv) {

	const int width = 1920;
	const int height = 1080;
	bool success = Game::GetInstance(width, height)->Initialize();
	
	const int wallThickness = 15;
	Color wallColor(255, 100, 255);
	Renderer* topWall = new Wall(0, 0, width, wallThickness, wallColor, RenderType::Static);
	Renderer* rightWall = new Wall(width - wallThickness, wallThickness, wallThickness, height, wallColor, RenderType::Static);
	Renderer* bottomWall = new Wall(0, height - wallThickness, width, wallThickness, wallColor, RenderType::Static);

	const int paddleHeight = 100;
	const int paddleWidth = 15;
	Color paddleColor(255, 255, 255);
	Renderer* paddle = new Paddle(10, (height / 2), paddleWidth, paddleHeight, paddleColor);

	const int ballSize= 10;
	Color BallColor(255, 255, 0);
	Renderer* ball = new Ball(width / 2, height / 2, ballSize, ballSize, BallColor);

	if (success) 
	{
		Game::GetInstance()->RunLoop();
	}

	Game::GetInstance()->Shutdown();

	return 0;
}