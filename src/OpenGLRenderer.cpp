#include <glad/glad.h>
#include "OpenGLRenderer.h"


void rdr::OpenGLRenderer::initialize(
      GLFWwindow* window
    , const glm::vec4& clearColor
    , const std::filesystem::path& vertexShaderPath
    , const std::filesystem::path& fragmentShaderPath)
{
    m_window = window;
    // load OpenGL DLLs
    // TODO: handle errors
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);

    m_shaderProgram = ShaderProgram(vertexShaderPath, fragmentShaderPath);
}