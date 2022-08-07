cmake_minimum_required(VERSION 3.21)
project(SideScrollShooter)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "D:/Prog/Env/Libraries/SFML-2.5.1-64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I${SFML_DIR}/include -L${SFML_DIR}/lib")

add_executable(${PROJECT_NAME} main.cpp Bases/Interfaces/IUpdatable.hpp GameSources/Player.cpp GameSources/Player.hpp GameSources/Game.cpp GameSources/Game.hpp GameSources/Enemy.cpp GameSources/Enemy.hpp Utility/PCH.hpp Bases/GameObject.cpp Bases/GameObject.hpp Utility/Timer.cpp Utility/Timer.hpp Utility/PCH.cpp Bases/Controller.cpp Bases/Controller.hpp Bases/EnemyController.cpp Bases/EnemyController.hpp Utility/EventDispatcher.hpp Bases/Interfaces/ISceneObject.hpp Bases/Interfaces/ISprite.hpp Bases/ImplSfml/SfmlSprite.cpp Bases/ImplSfml/SfmlSprite.hpp Bases/ImplSfml/SfmlResourceFactory.cpp Bases/ImplSfml/SfmlResourceFactory.hpp Bases/Interfaces/IResourceFactory.hpp Bases/Interfaces/ITexture.hpp Bases/ImplSfml/SfmlTexture.cpp Bases/ImplSfml/SfmlTexture.hpp Bases/Interfaces/IDestructable.hpp Bases/ImplSfml/Vector2.hpp)

## In most cases better set in the CMake cache

#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(Bases)
include_directories(Bases/ImplSfml)
include_directories(Bases/Interfaces)
include_directories(GameSources)
include_directories(Utility)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)