#pragma once

#include <Texture.h>

namespace rdr
{
    struct DrawCall
    {
        //using VextexData = glm::vec<5, float>;

        const Texture* texture;
        glm::vec3 position;
        
        //std::vector<VextexData> vertices;
    };
}