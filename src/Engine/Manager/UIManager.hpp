#pragma once
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include "UI/Common/Label.hpp"
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class UIManager
{
public:
	static std::vector<std::unique_ptr<Widget>> LoadFromFile(const std::string& FilePath);
};