#include "OpenGLGLFWContext.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <string_utils.h>


namespace
{
    void framebufferSizeCallback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

    const std::string_view GLSLVersion = "#version 330 core";
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

    glfwSetFramebufferSizeCallback(m_window, &framebufferSizeCallback);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init(GLSLVersion.data());
}

rdr::OpenGLGLFWContext::~OpenGLGLFWContext()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
}

bool rdr::OpenGLGLFWContext::windowShoudNotClose() const noexcept(true)
{
    return !glfwWindowShouldClose(m_window);
}

glm::ivec2 rdr::OpenGLGLFWContext::getWindowSize() const noexcept(true)
{
    glm::ivec2 result;

    glfwGetWindowSize(m_window, &result.x, &result.y);

    return result;
}

void rdr::OpenGLGLFWContext::onFrameStart()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void rdr::OpenGLGLFWContext::onFrameEnd()
{
    const double frameEndTimeStamp = glfwGetTime();
    m_FPS = static_cast<unsigned>(1. / (frameEndTimeStamp - m_lastTimeStamp));
    m_lastTimeStamp = frameEndTimeStamp;

    bool s = true;
    ImGui::ShowDemoWindow(&s);

    glfwSetWindowTitle(m_window, estd::format("%s, fps: %u", m_title.c_str(), m_FPS).c_str());

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}
