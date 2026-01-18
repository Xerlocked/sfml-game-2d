#include "UIManager.hpp"
#include <iostream>

std::vector<std::unique_ptr<Widget>> UIManager::LoadFromFile(const std::string& FilePath)
{
	std::vector<std::unique_ptr<Widget>> Widgets;

	std::ifstream file(FilePath);
	if (!file.is_open())
		return Widgets;

	json data;
	file >> data;

	for (const auto& Item : data["widgets"])
	{
		std::string type = Item.value("type", "Unknown");

		if (type == "Label")
		{
			std::string name = Item.value("name", "Label");

			std::string	 textValue = Item.value("text", "Default Text"); // 키가 없을 때를 대비한 기본값 설정
			int			 fontId = Item.value("font", 1000);
			unsigned int size = Item.value("size", 30);

			auto label = std::make_unique<Label>(
				name,
				sf::String::fromUtf8(textValue.begin(), textValue.end()),
				fontId,
				size);

			// 피봇 설정
			if (Item.contains("pivot") && Item["pivot"].is_array())
			{
				float pX = Item["pivot"].at(0).get<float>();
				float pY = Item["pivot"].at(1).get<float>();
				label->SetPivot(pX, pY);
			}
			else
			{
				label->SetPivot(0.5f, 0.5f); // 기본값 중앙 정렬
			}

			// 위치 설정
			if (Item.contains("pos") && Item["pos"].is_array())
			{
				try
				{
					float X = Item["pos"].at(0).get<float>();
					float Y = Item["pos"].at(1).get<float>();
					label->SetPosition({ X, Y });
				}
				catch (const json::exception& e)
				{
					std::cerr << "JSON Pos Error: " << e.what() << std::endl;
				}
			}

			Widgets.push_back(std::move(label));
		}
	}

	return Widgets;
}