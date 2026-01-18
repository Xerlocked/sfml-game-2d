#include "EntryScene.hpp"
#include "Manager/AssetManager.hpp"
#include "Manager/UIManager.hpp"
#include "Identify.hpp"

EntryScene::EntryScene()
{
	SceneWidgets = UIManager::LoadFromFile("Assets/UI/Entry.json");
}

void EntryScene::Init(sf::RenderWindow& Wnd)
{
	OnResize(Wnd.getSize());
}

void EntryScene::HandleInput(sf::RenderWindow& Wnd)
{
}

void EntryScene::Update(float DeltaTime)
{
}

void EntryScene::Render(sf::RenderWindow& Wnd)
{

	// UI Render
	RenderUI(Wnd);
}

void EntryScene::OnResize(const sf::Vector2u& NewSize)
{
	for (const auto& Widget : SceneWidgets)
	{
		Widget->OnResize(NewSize);
	}
}
