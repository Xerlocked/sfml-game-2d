#pragma once
#include "Core/Scene.hpp"

class EntryScene : public Scene
{
public:
	EntryScene();

	void Init(sf::RenderWindow& Wnd) override;
	void HandleInput(sf::RenderWindow& Wnd) override;
	void Update(float DeltaTime) override;
	void Render(sf::RenderWindow& Wnd) override;
	void OnResize(const sf::Vector2u& NewSize) override;
};