#include <glad/glad.h>
#include "OpenGLRenderer.h"


const float VoxelVertexData[] = {
     0.5f,  0.5f, 0.0f, 1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f, 0.0f, 1.0f    // top left 
};

void rdr::OpenGLRenderer::initialize(
      const glm::vec4& clearColor
    , const std::filesystem::path& vertexShaderPath
    , const std::filesystem::path& fragmentShaderPath)
{
    // load OpenGL DLLs
    // TODO: handle errors
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);

    //m_shaderProgram = ShaderProgram(vertexShaderPath, fragmentShaderPath);

    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void rdr::OpenGLRenderer::render(std::vector<rdr::DrawCall>& drawCalls)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //std::sort(drawCalls.begin(), drawCalls.end(), [](const rdr::DrawCall& a, const rdr::DrawCall& b)
    //{
    //    return a.texture < b.texture;
    //});

    for (const auto& drawCall : drawCalls)
    {
        //verticesData.insert(verticesData.cend(), drawCall.vertices);
    }
}
