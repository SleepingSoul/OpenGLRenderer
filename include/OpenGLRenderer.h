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
        void initialize(
              const glm::vec4& clearColor
            , const std::filesystem::path& vertexShaderPath
            , const std::filesystem::path& fragmentShaderPath);

        void setCameraPosition(const glm::vec3& cameraPosition);
        void render(std::vector<DrawCall>& drawCalls);

        bool isValidState() const { return m_window && m_shaderProgram; }

    private:
        GLFWwindow* m_window;
        ShaderProgram m_shaderProgram;
        GLuint m_VBO;
        GLuint m_VAO;
    };
}
