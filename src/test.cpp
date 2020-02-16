#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGLRenderer.h>
#include <OpenGLGLFWContext.h>

int main()
{
    rdr::OpenGLGLFWContext::InitParameters params;
    params.verMajor = 3;
    params.verMinor = 3;
    params.windowWidth = 800;
    params.windowHeight = 600;
    params.windowTitle = "OpenGLRenderer test";
    rdr::OpenGLGLFWContext context(params);

    rdr::OpenGLRenderer renderer;

    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    GLuint VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
    };

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    rdr::ShaderProgram shader("data/test_shader.vs", "data/test_shader.fs");
    shader.use();

    while (context.windowShoudNotClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_LINE_LOOP, 0, 3);
        glPointSize(5.f);
        glDrawArrays(GL_POINTS, 0, 3);

        context.onFrameEnd();
    }

}