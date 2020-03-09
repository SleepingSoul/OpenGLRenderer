#pragma once

#include <exception>
#include <string_view>
#include <functional>
#include <utils.h>

struct GLFWwindow;

namespace rdr
{
    DeclareInfoException(WindowCreationFailed);
    DeclareInfoException(OpenGLDynamicSymbolsBindingError);

    struct WindowSize
    {
        unsigned width{ 0 };
        unsigned height{ 0 };
    };

    class OpenGLGLFWContext
    {
    public:
        struct InitParameters
        {
            int verMajor{ 0 };
            int verMinor{ 0 };
            std::string windowTitle;
            unsigned windowHeight{ 0 };
            unsigned windowWidth{ 0 };
        };

        explicit OpenGLGLFWContext(const InitParameters& initParams);
        ~OpenGLGLFWContext();

        OpenGLGLFWContext(const OpenGLGLFWContext&) = delete;
        OpenGLGLFWContext& operator =(const OpenGLGLFWContext&) = delete;
        OpenGLGLFWContext(OpenGLGLFWContext&&) = delete;
        OpenGLGLFWContext& operator =(OpenGLGLFWContext&&) = delete;

        bool windowShoudNotClose() const noexcept(true);
        WindowSize getWindowSize() const noexcept(true);
        void onFrameEnd();

    private:
        GLFWwindow* m_window;
        std::string m_title;
        double m_lastTimeStamp{ 0. };
        unsigned m_FPS{ 0 };
        std::function<void(int, int)> onResize;
    };
}
