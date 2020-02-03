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

rdr::CubeMap::CubeMap(std::array<std::filesystem::path, 6> cubeMapTextures)
{
    for (const auto& path : cubeMapTextures)
    {

    }

    m_data = stbi_load(m_path.u8string().c_str(), &m_width, &m_height, &m_numChannels, 0);

    if (!m_data)
    {
        return;
    }

    glCreateTextures(GL_TEXTURE_CUBE_MAP, 1, &m_id);
    glTextureParameteri(m_id, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(m_id, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    const auto format = channelsNumberToFormat(m_numChannels);
    glTexStorage2D(m_id, )
    glTexImage2D(m_id, 0, format, static_cast<GLsizei>(m_width), static_cast<GLsizei>(m_height), 0, format, GL_UNSIGNED_BYTE, m_data);
    glGenerateTextureMipmap(m_id);

    stbi_image_free(m_data);
}
