#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>

class AssetManager
{
public:
	static AssetManager& Get()
	{
		static AssetManager Instance;
		return Instance;
	}

	void			LoadFont(int AssetID, const std::string& FileName);
	const sf::Font& GetFont(int AssetID) const;

	void			   LoadTexture(int AssetID, const std::string& FileName);
	const sf::Texture& GetTexture(int AssetID) const;

private:
	AssetManager() = default;

	std::map<int, sf::Font>	   Fonts;
	std::map<int, sf::Texture> Textures;
};