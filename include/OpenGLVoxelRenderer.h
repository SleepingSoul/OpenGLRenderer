#pragma once

#include <filesystem>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <ShaderProgram.h>
#include "DrawCall.h"


namespace rdr
{
    class OpenGLVoxelRenderer
    {
    public:
        OpenGLVoxelRenderer();
        void setClearColor(const glm::vec4& rgbaColor);
        void renderVoxels();

    private:
        GLuint m_voxelVBO;
        GLuint m_voxelVAO;
        ShaderProgram m_voxelShader;
    };
}
