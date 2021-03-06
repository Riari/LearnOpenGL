#include "Entity/Entity.hpp"
#include "Entity/EntityManager.hpp"
#include "Utility/String.hpp"

using namespace Iris;

EntityManager& EntityManager::GetInstance()
{
    static EntityManager instance;
    return instance;
}

std::vector<std::shared_ptr<Entity>> EntityManager::GetEntities()
{
    std::vector<std::shared_ptr<Entity>> entities;
    for (const auto& [id, entity] : m_entities)
    {
        entities.push_back(entity);
    }
    return entities;
}

std::string EntityManager::GenerateID()
{
    std::string id;
    do id = random_string(8);
    while (m_entities.find(id) != m_entities.end());

    return id;
}
