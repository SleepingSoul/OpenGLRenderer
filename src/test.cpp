#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <OpenGLVoxelRenderer.h>
#include <OpenGLGLFWContext.h>
#include <thread>
#include <future>


int main()
{
    auto retVal = std::async(std::launch::async, []
    {
        // Creating and initializing OpenGL context (should be always initialized before anything else opengl-ish).
        rdr::OpenGLGLFWContext::InitParameters params;
        params.verMajor = 3;
        params.verMinor = 3;
        params.windowWidth = 800;
        params.windowHeight = 600;
        params.windowTitle = "OpenGLRenderer test";
        rdr::OpenGLGLFWContext context(params);

        // After context is initialized, we can create an OpenGL Renderer to render using the existing context. Only 1 contexts exists
        // and renderer will render into this context.
        rdr::OpenGLVoxelRenderer renderer;

        while (context.windowShoudNotClose())
        {
            renderer.setClearColor(glm::vec4{ 0.f, 0.f, 0.f, 1.f });
            renderer.renderVoxels();

            context.onFrameEnd();
        }

        return 0;
    });

    return retVal.get();
}