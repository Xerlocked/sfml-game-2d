#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../UI/Widget/Widget.hpp"

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Init(sf::RenderWindow& Wnd) = 0;
	virtual void HandleInput(sf::RenderWindow& Wnd) = 0;
	virtual void Update(float DeltaTime) = 0;
	virtual void Render(sf::RenderWindow& Wnd) = 0;
	virtual void OnResize(const sf::Vector2u& NewSize) = 0;

protected:
	std::vector<std::unique_ptr<Widget>> SceneWidgets;

	void RenderUI(sf::RenderWindow& Wnd)
	{
		for (auto& Widget : SceneWidgets)
		{
			Widget->Render(Wnd);
		}
	}
};