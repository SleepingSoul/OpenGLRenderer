#pragma once

#include <filesystem>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <ShaderProgram.h>


namespace rdr
{
    class OpenGLRenderer
    {
    public:
        void initialize(
              GLFWwindow* window
            , const glm::vec4& clearColor
            , const std::filesystem::path& vertexShaderPath
            , const std::filesystem::path& fragmentShaderPath);

        // Any container of rdr::DrawCall's
        template <class TContainer>
        void render(const TContainer& drawCalls);

        bool inValidState() const { return m_window && m_shaderProgram; }

    private:
        GLFWwindow* m_window;
        ShaderProgram m_shaderProgram;
    };
}

#include "OpenGLRenderer.inl"
