#include "AssetManager.hpp"
#include <stdexcept>

void AssetManager::LoadFont(int AssetID, const std::string& FileName)
{
	sf::Font font;
	if (font.openFromFile(FileName))
	{
		Fonts[AssetID] = std::move(font);
	}
}

const sf::Font& AssetManager::GetFont(int AssetID) const
{
	return Fonts.at(AssetID);
}

void AssetManager::LoadTexture(int AssetID, const std::string& FileName)
{
	sf::Texture texture;
	if (texture.loadFromFile(FileName))
	{
		Textures[AssetID] = std::move(texture);
	}
}

const sf::Texture& AssetManager::GetTexture(int AssetID) const
{
	return Textures.at(AssetID);
}
