#include <SDL.h>
#include <list>
#include <iterator>
#include "Renderer.h"
#include "Vector.h"
#include "Physics.h"

#pragma once

class Game
{

public:
	Game(int width, int height);
	Game(Game& other) = delete;
	void operator=(const Game&) = delete;

public:
	static Game* GetInstance(int _width, int _height);
	static Game* GetInstance();

	//Initialize The Game.
	bool Initialize();

	//Runs the game loop until the game is over.
	void RunLoop();

	//shutdown the game.
	void Shutdown();

	/// <summary>
	/// Adds Into the list of Dynamic Objects to render.
	/// </summary>
	/// <param name="obje">Render Object to be added</param>
	void AddDynamicRenderObjects(Renderer* obje);

	/// <summary>
	/// Removes from the List of Dynamic objects
	/// </summary>
	/// <param name="obje">Render Object to be removed</param>
	void RemoveDynamicRenderObjects(Renderer* obje);

	/// <summary>
	/// Adds into the list of Static Render Objects
	/// </summary>
	/// <param name="obje">Render object to be added</param>
	void AddStaticRenderObjects(Renderer* obje);

	/// <summary>
	/// Removes from the list of dynamic Render objects
	/// </summary>
	/// <param name="obje">Render object to be removed</param>
	void RemoveStaticRenderObjects(Renderer* obje);

	/// <summary>
	/// Adds The Physics Object to the list
	/// </summary>
	/// <param name="obj"></param>
	void AddPhysicsObject(Physics* obj);

	/// <summary>
	/// Removes the Physical Object from the list
	/// </summary>
	/// <param name="obj"></param>
	void RemovePhysicsObject(Physics* obj);

private:

	void ProcessInput();

	void UpdateGame();
	
	void GenerateOutput();

	void RenderGameObjects();
	void RenderStaticObjects();
	void RenderDynamicObjects();

	//Window created by sdl
	SDL_Window* m_window;

	//SDL Renderer 
	SDL_Renderer* m_renderer;

	//Game should Continue to run.
	bool m_IsRunning;

	static int width, height;

	std::list<Renderer*> m_staticRenderObjects;
	std::list<Renderer*> m_dynamicRenderObjects;
	std::list<Physics*> m_physicsObject;
	
public:
	static Game* m_Instance;

};
