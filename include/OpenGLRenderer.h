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
              GLFWwindow* window
            , const glm::vec4& clearColor
            , const std::filesystem::path& vertexShaderPath
            , const std::filesystem::path& fragmentShaderPath);

        // Any container of rdr::DrawCall's

        void render(const std::vector<DrawCall>& drawCalls);

        bool isValidState() const { return m_window && m_shaderProgram; }

    private:
        GLFWwindow* m_window;
        ShaderProgram m_shaderProgram;
        GLuint m_VBO;
        GLuint m_VAO;
    };

    inline void OpenGLRenderer::render(const std::vector<rdr::DrawCall>& drawCalls)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        std::vector<float> verticesData;
        verticesData.reserve(drawCalls.size() * 5);

        for (const auto& drawCall : drawCalls)
        {
            //verticesData.insert(verticesData.cend(), drawCall.vertices);
        }
    }
}
