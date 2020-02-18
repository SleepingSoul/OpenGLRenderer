#include "OpenGLGLFWContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string_utils.h>


namespace rdr_private
{
    void framebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}

rdr::OpenGLGLFWContext::OpenGLGLFWContext(const InitParameters& initParams)
    : m_title(initParams.windowTitle)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, initParams.verMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, initParams.verMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (m_window = glfwCreateWindow(initParams.windowWidth, initParams.windowHeight, initParams.windowTitle.c_str(), NULL, NULL);
        m_window == nullptr)
    {
        const char* description;
        const int errorCode = glfwGetError(&description);
        throw WindowCreationFailed(estd::format("GLFW window creation failed. GLFW Error code: %d: %s", errorCode, description));
    }

    glfwMakeContextCurrent(m_window);

    const int dllLoadResult = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    if (!dllLoadResult)
    {
        throw OpenGLDynamicSymbolsBindingError(estd::format("GLAD load error. Code: %d", dllLoadResult));
    }

    glfwSetFramebufferSizeCallback(m_window, &rdr_private::framebufferSizeCallback);
}

rdr::OpenGLGLFWContext::~OpenGLGLFWContext()
{
    glfwTerminate();
}

bool rdr::OpenGLGLFWContext::windowShoudNotClose() const noexcept(true)
{
    return !glfwWindowShouldClose(m_window);
}

void rdr::OpenGLGLFWContext::onFrameEnd()
{
    const double frameEndTimeStamp = glfwGetTime();
    m_FPS = static_cast<unsigned>(1. / (frameEndTimeStamp - m_lastTimeStamp));
    m_lastTimeStamp = frameEndTimeStamp;

    glfwSetWindowTitle(m_window, estd::format("%s, fps: %u", m_title.c_str(), m_FPS).c_str());

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}
