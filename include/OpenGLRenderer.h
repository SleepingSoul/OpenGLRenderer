#pragma once

#include <filesystem>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <ShaderProgram.h>
#include "DrawCall.h"


namespace rdr
{
    class OpenGLRenderer
    {
    public:
        OpenGLRenderer();

        //void debugRender();
        
        void setClearColor(const glm::vec4& rgbaColor);

    private:
        GLuint m_VBO;
        GLuint m_VAO;
    };
}
