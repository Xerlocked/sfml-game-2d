#pragma once

#include "../Widget/Widget.hpp"
#include "../../Manager/AssetManager.hpp"
#include "../../Identify.hpp"

class Label : public Widget
{
public:
	Label(const std::string InName, const sf::String& Text, int FontId, unsigned int Size = 30);

	Label(const sf::String& Text, int FontId, unsigned int Size = 30);

	void Update(float DeltaTime) override;

	void Render(sf::RenderWindow& Wnd) override;

	void OnResize(const sf::Vector2u& NewSize) override;

	void ApplyPivot() override;

	void SetText(const sf::String& InText);

	void SetFontSize(const unsigned int Size);

private:
	sf::Text MainText;
};