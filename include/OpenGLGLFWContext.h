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

    class OpenGLGLFWContext
    {
    public:
        struct InitParameters
        {
            int verMajor;
            int verMinor;
            std::string windowTitle;
            unsigned windowHeight;
            unsigned windowWidth;
        };

        explicit OpenGLGLFWContext(const InitParameters& initParams);
        ~OpenGLGLFWContext();

        OpenGLGLFWContext(const OpenGLGLFWContext&) = delete;
        OpenGLGLFWContext& operator =(const OpenGLGLFWContext&) = delete;
        OpenGLGLFWContext(OpenGLGLFWContext&&) = delete;
        OpenGLGLFWContext& operator =(OpenGLGLFWContext&&) = delete;

        bool windowShoudNotClose() const noexcept(true);
        void onFrameEnd();

    private:
        GLFWwindow* m_window;
        std::string m_title;
        double m_lastTimeStamp{ 0. };
        unsigned m_FPS{ 0 };
        std::function<void(int, int)> onResize;
    };
}
