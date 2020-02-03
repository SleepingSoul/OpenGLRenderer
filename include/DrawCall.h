#pragma once

namespace rdr
{
    class CubeMap;
    class ShaderProgram;

    struct DrawCall
    {
        ShaderProgram* shader;
        const CubeMap* texture;
        glm::vec3 position;
    };
}