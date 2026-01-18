#include "Label.hpp"

Label::Label(const std::string InName, const sf::String& Text, int FontId, unsigned int Size) : MainText(AssetManager::Get().GetFont(FontId))
{
	Name = InName;
	SetText(Text);
	SetFontSize(Size);
}

Label::Label(const sf::String& Text, int FontId, unsigned int Size) : MainText(AssetManager::Get().GetFont(FontId))
{
	SetText(Text);
	SetFontSize(Size);
}

void Label::Update(float DeltaTime)
{
}

void Label::Render(sf::RenderWindow& Wnd)
{
	if (bIsVisible)
	{
		Wnd.draw(MainText);
	}
}

void Label::OnResize(const sf::Vector2u& NewSize)
{
	ApplyPivot();

	float CorrectSizeX = NewSize.x * RelativePosition.x;
	float CorrectSizeY = NewSize.y * RelativePosition.y;

	MainText.setPosition({ CorrectSizeX, CorrectSizeY });
}

void Label::ApplyPivot()
{
	sf::FloatRect Bounds = MainText.getLocalBounds();

	float OriginX = Bounds.position.x + Bounds.size.x * Pivot.x;
	float OriginY = Bounds.position.y + Bounds.size.y * Pivot.y;

	MainText.setOrigin({ OriginX, OriginY });
}

void Label::SetText(const sf::String& InText)
{
	MainText.setString(InText);
	ApplyPivot();
}

void Label::SetFontSize(const unsigned int Size)
{
	MainText.setCharacterSize(Size);
}
