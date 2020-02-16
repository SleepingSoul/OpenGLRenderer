#include <glad/glad.h>
#include "OpenGLRenderer.h"


rdr::OpenGLRenderer::OpenGLRenderer()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);

    glGenBuffers(1, &m_VBO);
    glGenVertexArrays(1, &m_VAO); 
    glBindVertexArray(m_VAO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void rdr::OpenGLRenderer::setClearColor(const glm::vec4& rgbaColor)
{
    glClearColor(rgbaColor.r, rgbaColor.g, rgbaColor.b, rgbaColor.a);
}
