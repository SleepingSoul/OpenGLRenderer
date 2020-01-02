#pragma once

#include <Texture.h>

namespace rdr
{
    struct DrawCall
    {
        const Texture* texture;
        glm::vec2 uvTopLeft;
        glm::vec2 uvDownRight;
        glm::vec3 position;
        
        std::vector<glm::vec3> vertices;
    };
}