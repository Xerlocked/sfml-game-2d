#pragma once
#include <SFML/Graphics.hpp>

class Widget
{
public:
	virtual ~Widget() = default;
	virtual void Update(float DeltaTime) = 0;
	virtual void Render(sf::RenderWindow& Wnd) = 0;
	virtual void OnResize(const sf::Vector2u& NewSize) = 0;
	virtual void ApplyPivot() {};

	void SetPosition(sf::Vector2f Position) { RelativePosition = Position; }
	void SetPivot(float InX, float InY) { Pivot = { InX, InY }; }
	void SetVisible(bool Visibility) { bIsVisible = Visibility; }
	bool GetVisiblity() { return bIsVisible; }

protected:
	std::string	 Name;
	bool		 bIsVisible = true;
	sf::Vector2f RelativePosition;
	sf::Vector2f Pivot = { 0.5f, 0.5f };
};