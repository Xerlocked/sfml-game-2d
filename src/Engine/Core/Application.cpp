#include "Application.hpp"
#include "../Manager/AssetManager.hpp"
#include "Scene/EntryScene.hpp"
#include "../Identify.hpp"

Application::Application() : AppWindow(sf::VideoMode({ 1024, 768 }), "Game Launcher")
{
	AssetManager::Get().LoadFont(Asset::Font::Default, "Assets/Fonts/Mulmaru.ttf");

	AppWindow.setFramerateLimit(60);

	ActiveScene = std::make_unique<EntryScene>();
	ActiveScene->Init(AppWindow);
}

void Application::Run()
{
	while (AppWindow.isOpen())
	{
		float DeltaTime = AppClock.restart().asSeconds();

		ProcessEvents();
		Update(DeltaTime);
		Render();
	}
}

void Application::ProcessEvents()
{
	while (const std::optional event = AppWindow.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			AppWindow.close();
		}

		if (const auto* resized = event->getIf<sf::Event::Resized>())
		{
			sf::Vector2u NewSize = resized->size;

			sf::FloatRect VisibleArea({ 0.f, 0.f }, { (float)NewSize.x, (float)NewSize.y });
			AppWindow.setView(sf::View(VisibleArea));

			if (ActiveScene)
			{
				ActiveScene->OnResize(NewSize);
			}
		}
	}
}

void Application::Update(float DeltaTime)
{
	if (ActiveScene)
	{
		ActiveScene->Update(DeltaTime);
	}
}

void Application::Render()
{
	AppWindow.clear(sf::Color(0, 0, 0));

	if (ActiveScene)
	{
		ActiveScene->Render(AppWindow);
	}

	AppWindow.display();
}
