#pragma once

#include <filesystem>
#include <array>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace rdr
{
    class CubeMap
    {
    public:
        using TextureID = GLuint;

        struct TextureData
        {
            TextureID id{ 0 };
            GLsizei width{ 0 };
            GLsizei height{ 0 };
        };

        CubeMap(std::array<std::filesystem::path, 6> cubeMapTextures);

        auto getSizeOf(std::size_t index) const { return glm::ivec2(m_width, m_height); }

        bool isValid() const { m_width > 0 && m_height > 0 && m_numChannels > 0; }
        operator bool() const { return isValid(); }

    private:
        std::array<TextureData, 6> m_cubeMapTextures;
        int m_width{ 0 };
        int m_height{ 0 };
        int m_numChannels{ 0 };

        std::filesystem::path m_path;
    };
}
