#pragma once

#include <map>
#include <memory>
#include <set>
#include <vector>

#include "Exception/Exception.hpp"

namespace Iris
{
    class RenderableEntity;

    class EntityManager
    {
    public:
        EntityManager(EntityManager const&) = delete;
        void operator=(EntityManager const&) = delete;

        static EntityManager& GetInstance();

        template <typename T, typename... Args>
        std::enable_if_t<
                std::is_constructible<T, std::string, Args...>::value,
                std::shared_ptr<T>
        >
        CreateEntity(Args&&... args) {
            auto id = GenerateID();
            auto pEntity = std::make_shared<T>(id, std::forward<Args>(args)...);
            m_entities.insert(std::pair(id, pEntity));
            return pEntity;
        }

        template <typename T, typename... Args>
        std::enable_if_t<
                !std::is_constructible<T, std::string, Args...>::value,
                std::shared_ptr<T>
        >
        CreateEntity(Args&&...)
        {
            throw Exception("Tried to create entity but supplied args incompatible.");
        }

        std::vector<std::shared_ptr<Entity>> GetEntities();

    private:
        std::map<std::string, std::shared_ptr<Entity>> m_entities;

        EntityManager() = default;

        std::string GenerateID();
    };
}