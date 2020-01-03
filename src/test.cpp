#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGLRenderer.h>

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    rdr::OpenGLRenderer renderer;
    renderer.initialize(window, { 0.2f, 0.3f, 0.3f, 1.0f }, "", "");

    while (!glfwWindowShouldClose(window))
    {
        renderer.render({});

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}