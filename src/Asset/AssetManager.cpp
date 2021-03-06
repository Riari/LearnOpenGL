#include "Asset/AssetManager.hpp"

using namespace Iris;

AssetManager::AssetManager() : m_images(new ImageRepository)
{}

std::shared_ptr<Image> AssetManager::GetImage(std::string path) const
{
    return m_images->Get(std::move(path));
}

void AssetManager::UnloadImage(const std::string &path) const
{
    m_images->Unload(path);
}