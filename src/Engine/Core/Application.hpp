#pragma once

#include <memory>
#include "Scene.hpp"

class Application
{
public:
	Application();
	void Run();

private:
	void ProcessEvents();		  // Input
	void Update(float DeltaTime); // Logic
	void Render();				  // View

private:
	sf::RenderWindow	   AppWindow;
	std::unique_ptr<Scene> ActiveScene;
	sf::Clock			   AppClock;
};