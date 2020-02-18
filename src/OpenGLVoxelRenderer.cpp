#include <glad/glad.h>
#include "OpenGLVoxelRenderer.h"


rdr::OpenGLVoxelRenderer::OpenGLVoxelRenderer()
    : m_voxelShader("data/test_shader.vs", "data/test_shader.fs")
{
    glClearColor(0.f, 0.f, 0.f, 1.f);

    glGenVertexArrays(1, &m_voxelVAO);
    glGenBuffers(1, &m_voxelVBO);

    glBindBuffer(GL_ARRAY_BUFFER, m_voxelVBO);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(m_voxelVAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void rdr::OpenGLVoxelRenderer::setClearColor(const glm::vec4& rgbaColor)
{
    glClearColor(rgbaColor.r, rgbaColor.g, rgbaColor.b, rgbaColor.a);
}

void rdr::OpenGLVoxelRenderer::renderVoxels()
{
    glClear(GL_COLOR_BUFFER_BIT);

    const float timeValue = static_cast<float>(glfwGetTime());
    float greenValue = sin(timeValue) / 2.0f + 0.5f;

    m_voxelShader.use();
    m_voxelShader.setVec4f("debugColor", glm::vec4(0.f, greenValue, 0.f, 1.f));

    glDrawArrays(GL_LINE_LOOP, 0, 3);
    glPointSize(5.f);
    glDrawArrays(GL_POINTS, 0, 3);
}