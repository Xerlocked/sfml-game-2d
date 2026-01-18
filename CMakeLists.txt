cmake_minimum_required(VERSION 3.28)
project(Kiwi LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

include(FetchContent)
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(json)

add_executable(main 
    src/Engine/GEngine.cpp
    src/Engine/Core/Application.cpp
    src/Engine/Manager/AssetManager.cpp
    src/Engine/Manager/UIManager.cpp
    src/Engine/UI/Common/Label.cpp
    
    src/Game/Scene/EntryScene.cpp
)
target_compile_features(main PRIVATE cxx_std_17)
target_include_directories(main PRIVATE src/Engine src/Game)
target_link_libraries(main PRIVATE SFML::Graphics nlohmann_json::nlohmann_json)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)