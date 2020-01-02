#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


namespace
{
    GLenum channelsNumberToFormat(int channelsNumber)
    {
        switch (channelsNumber)
        {
        case 1:
            return GL_RED;
        case 3:
            return GL_RGB;
        case 4:
            return GL_RGBA;
        default:
            return GL_NONE;
        }
    }
}

rdr::Texture::Texture(std::filesystem::path texturePath)
    : m_path(std::move(texturePath))
{
    int width, height, channelsNumber;
    m_data = stbi_load(m_path.u8string().c_str(), &m_width, &m_height, &m_numChannels, 0);

    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
}

rdr::Texture::~Texture()
{
    stbi_image_free(m_data);
}

void rdr::Texture::loadToGPU()
{
    glBindTexture(GL_TEXTURE_2D, m_id);
    if (m_data)
    {
        auto const format = channelsNumberToFormat(m_numChannels);
        glTexImage2D(GL_TEXTURE_2D, 0, format, static_cast <GLsizei>(m_width), static_cast <GLsizei>(m_height),
            0, format, GL_UNSIGNED_BYTE, m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    glBindTexture(GL_TEXTURE_2D, 0);

    m_isInGPU = true;
}

void rdr::Texture::unloadFromGPU()
{
    glDeleteTextures(1, &m_id);
    m_isInGPU = false;
}


