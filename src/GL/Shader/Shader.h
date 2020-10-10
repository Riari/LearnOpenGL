#pragma once

#include <iostream>
#include <memory>

#include <glad/glad.h>
#include <spdlog/spdlog.h>

class Shader
{
public:
    Shader(GLenum type, const std::string &name, const std::string &suffix, std::shared_ptr<spdlog::logger> logger);

    ~Shader();

    [[nodiscard]] unsigned int GetID() const;

    void Compile() const;

private:
    const unsigned int m_id;
    const std::string m_name;
    const std::string m_path = "resources\\shaders\\";
    const std::string m_extension = ".glsl";

    std::shared_ptr<spdlog::logger> m_logger;

    [[nodiscard]] std::string LoadSource() const;
};
