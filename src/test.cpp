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

        try
        {
            rdr::OpenGLGLFWContext context(params);


            // After context is initialized, we can create an OpenGL Renderer to render using the existing context. Only 1 contexts exists
            // and renderer will render into this context.
            rdr::OpenGLVoxelRenderer renderer;

            std::vector<rdr::VoxelDrawCall> rdc(5);

            for (size_t i = 0; i < rdc.size(); ++i)
            {
                rdc[i].angle = 30.f;
                rdc[i].position = { 0.f - static_cast<float>(i), 0.f, 0.f };
                rdc[i].position += glm::vec3{ 0.2f, 0.2f, 0.2f };
                rdc[i].rotationVec = { 0.2f, 0.2f, 0.2f };
            }

            while (context.windowShoudNotClose())
            {
                context.onFrameStart();

                renderer.setClearColor(glm::vec4{ 0.f, 0.f, 0.f, 1.f });

                renderer.setCameraPosition({ 0.f, 0.f, -5.f });
                renderer.setRenderField(context.getWindowSize());
                renderer.setDebugRender(true);

                renderer.renderVoxels(rdc);

                context.onFrameEnd();
            }

            return 0;
        }
        catch (const rdr::OpenGLDynamicSymbolsBindingError & err)
        {
            std::puts(err.what());
            return -1;
        }
        catch (const rdr::WindowCreationFailed & err)
        {
            std::puts(err.what());
            return -1;
        }
    });


    return retVal.get();
}