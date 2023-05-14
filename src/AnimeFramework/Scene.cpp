#include "ComponentManager.hpp"
#include "Scene.hpp"

#include <memory>
#include <string>
#include <vector>

using namespace AnimeDefendersEngine;

auto Scene::addEntity(std::shared_ptr<Entity>) -> void {}

auto Scene::deleteEntity(std::string entityId) -> void {}
