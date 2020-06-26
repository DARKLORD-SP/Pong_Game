#include "Game.h"
#include <iostream>

//Initializes the pointer to null so that it can initialze during the first call of getInstance;
Game* Game::m_Instance = nullptr;

int Game::width = 0;
int Game::height = 0;

Game::Game(int width = 0, int height = 0)
{
	m_window = nullptr;
	m_renderer = nullptr;
	m_IsRunning = true;
	this->width = width;
	this->height = height;

	keyboardState = nullptr;
}

Game::~Game()
{
	delete  m_window;
	delete  m_renderer;
	delete  keyboardState;
}

Game* Game::GetInstance(int _width, int _height)
{
	if (m_Instance == nullptr)
		m_Instance = new Game(_width, _height);

	return m_Instance;
}

Game* Game::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new Game(width, height);

	return m_Instance;
}

/// <summary>
/// Initializes the SDL and Creates A Window
/// </summary>
/// <returns></returns>
bool Game::Initialize()
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);

	//Intialization Failed
	if (sdlResult != 0) {
		SDL_Log("Unable to Initialize SLD: %s", SDL_GetError());
		return false;
	}
	else
		SDL_Log("SDL Initialized!");
	
	m_window = SDL_CreateWindow("Pong Game", 100, 100, width, height, SDL_WINDOW_FULLSCREEN);

	//Window Creation Failed
	if (!m_window)
	{
		SDL_Log("Failed to create a Window %s", SDL_GetError());
		return false;
	}
	else
		SDL_Log("SDL Window Created with width = %d, height = %d", width, height);

	//SDL_ACCELERATED used The graphics hardware to render, presentvsync means enalbes vsync. -1, means which graphics driver to use if the game has only single window than -1 is perfect which means let the sdl decide.
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//renderer creation failed.
	if (!m_renderer) {
		SDL_Log("Failed to create a renderer %s", SDL_GetError());
		return false;
	}
	else
		SDL_Log("SDL Renderer Created with driver %d, and with %s hardware, And VSync is %s", -1, "Graphics card", "Enabled");

	return true;
}

void Game::SetFPS(float fps)
{
	Time::SetFPS(fps);
}

/// <summary>
/// Game Loop until the game has stopped, this function will keep on running.
/// </summary>
void Game::RunLoop()
{
	while (m_IsRunning) 
	{
		UpdateGameTime();
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}

}

/// <summary>
/// Shuts down the Game
/// </summary>
void Game::Shutdown()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Game::AddDynamicRenderObjects(Renderer* obje)
{
	m_dynamicRenderObjects.push_front(obje);
}

void Game::RemoveDynamicRenderObjects(Renderer* obje)
{	
	std::list<Renderer*>::iterator iter;

	for (iter = m_dynamicRenderObjects.begin(); iter != m_dynamicRenderObjects.end(); ++iter)
	{
		if (*iter == obje)
		{
			m_dynamicRenderObjects.remove(obje);
			break;
		}
	}
}

void Game::AddStaticRenderObjects(Renderer* obje)
{
	m_staticRenderObjects.push_front(obje);
}

void Game::RemoveStaticRenderObjects(Renderer* obje)
{
	std::list<Renderer*>::iterator iter;

	for (iter = m_staticRenderObjects.begin(); iter != m_staticRenderObjects.end(); ++iter)
	{
		if (*iter == obje)
		{
			m_staticRenderObjects.remove(obje);
			break;
		}
	}
}

void Game::AddPhysicsObject(Physics* obj)
{
	m_physicsObject.push_front(obj);
}

void Game::RemovePhysicsObject(Physics* obj)
{
	std::list<Physics*>::iterator iter;

	for (iter = m_physicsObject.begin(); iter != m_physicsObject.end(); iter++) 
	{
		if (*iter == obj) 
		{
			m_physicsObject.remove(obj);
			break;
		}
	}
}

void Game::UpdateGameTime()
{
	//Update The Game Time Every Game loop
	Time::UpdateDeltaTime();
}

void Game::ProcessInput()
{
	SDL_Event event;

	//while there are still events in the queue
	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
			//if the event recieved is quit then close the game.
			case SDL_QUIT:
			{
				m_IsRunning = false;
			}
			break;
		}
	}

	//Stores the entire keyboard state in a array
	keyboardState = SDL_GetKeyboardState(NULL);

	//checks for the escape keys index state.
	if (keyboardState[SDL_SCANCODE_ESCAPE]) {
		m_IsRunning = false;
	}
}

/// <summary>
/// Updates the Objects Position in world
/// </summary>
void Game::UpdateGame()
{
	std::list<Physics*>::iterator physicsIter;

	for (physicsIter = m_physicsObject.begin(); physicsIter != m_physicsObject.end(); physicsIter++)
	{
		UpdatePaddle(physicsIter);
	}

}

void Game::UpdatePaddle(std::list<Physics*>::iterator physicsIter)
{
	//Movements for paddle object
	if (physicsIter._Ptr->_Myval->GetTypeOfObject() == GameObject::Paddle) {
		//W key is pressed
		if (keyboardState[SDL_SCANCODE_W])
			physicsIter._Ptr->_Myval->SetDirection(Vector(0, -1));
		//S key is Pressed
		else if (keyboardState[SDL_SCANCODE_S])
			physicsIter._Ptr->_Myval->SetDirection(Vector(0, 1));
		else
			physicsIter._Ptr->_Myval->SetDirection(Vector(0, 0));

		//lerping the Velocity if any key has pressed.
		if (physicsIter._Ptr->_Myval->GetDirection().x != 0 || physicsIter._Ptr->_Myval->GetDirection().y != 0) {
			Vector vel = physicsIter._Ptr->_Myval->GetVelocity();
			vel += Vector(0, Utility::Lerp(vel.y, physicsIter._Ptr->_Myval->GetSpeed(), 0.02f));

			physicsIter._Ptr->_Myval->SetVelocity(vel);

			physicsIter._Ptr->_Myval->Move(physicsIter._Ptr->_Myval->GetVelocity().y * Time::GetDeltaTime());			
		}
		else {
			physicsIter._Ptr->_Myval->SetVelocity(Vector(0, 0));
		}

	}
}

void Game::GenerateOutput()
{
	//Draws a color to the back buffer
	SDL_SetRenderDrawColor(m_renderer, 175, 175, 255, 255);

	//Clears the renderer to display the current buffer
	SDL_RenderClear(m_renderer);

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	RenderGameObjects();

	//Swaps the back and front buffers and displays the back buffer which was colored red.
	SDL_RenderPresent(m_renderer);

}

void Game::RenderGameObjects()
{
	RenderStaticObjects();
	RenderDynamicObjects();
}

void Game::RenderStaticObjects()
{
	std::list<Renderer*>::iterator iter;

	for (iter = m_staticRenderObjects.begin(); iter != m_staticRenderObjects.end(); iter++) 
	{
		//Sets the color for the static object r, g, b, a
		SDL_SetRenderDrawColor(m_renderer, iter._Ptr->_Myval->m_color->r, iter._Ptr->_Myval->m_color->g, iter._Ptr->_Myval->m_color->b, 255);
		
		//Draws the Object
		SDL_RenderFillRect(m_renderer, iter._Ptr->_Myval->RenderRectangle());
	}

}

void Game::RenderDynamicObjects()
{
	std::list<Renderer*>::iterator iter;
	
	for (iter = m_dynamicRenderObjects.begin(); iter != m_dynamicRenderObjects.end(); iter++) 
	{
		//Sets the Color for the Dynamic object r, g, b, a
		SDL_SetRenderDrawColor(m_renderer, iter._Ptr->_Myval->m_color->r, iter._Ptr->_Myval->m_color->g, iter._Ptr->_Myval->m_color->b, 255);

		//Draws the Object
		SDL_RenderFillRect(m_renderer, iter._Ptr->_Myval->RenderRectangle());

		//Debug for Pivot 
		/*
		SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
		SDL_Rect* pivot = new SDL_Rect();
		pivot->x = iter._Ptr->_Myval->RenderRectangle()->x;
		pivot->y = iter._Ptr->_Myval->RenderRectangle()->y;
		pivot->w = 5;
		pivot->h = 5;
		SDL_RenderFillRect(m_renderer, pivot);*/
	}
}