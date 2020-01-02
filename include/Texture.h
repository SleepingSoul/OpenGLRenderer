#pragma once

#include <filesystem>
#include <glad/glad.h>
#include <glm/glm.hpp>

namespace rdr
{
    class Texture
    {
    public:
        using TextureID = GLuint;

        Texture(std::filesystem::path textureFile);
        ~Texture();


        auto getSize() const { return glm::ivec2(m_width, m_height); }

        void loadToGPU();
        void unloadFromGPU();
        bool isInGPU() const { return m_isInGPU; }

        const auto& getPath() const { return m_path; }

        bool isValid() const { m_width > 0 && m_height > 0 && m_numChannels > 0; }
        operator bool() const { return isValid(); }

    private:
        unsigned char* m_data;
        TextureID m_id;
        int m_width;
        int m_height;
        int m_numChannels;

        std::filesystem::path m_path;
        bool m_isInGPU;
    };
}
