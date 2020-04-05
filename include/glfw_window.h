#pragma once

#include <functional>

class GLFWwindow;

namespace glfw {

class Window
{
public:
    Window(unsigned int width, unsigned int height, std::string const &title);
    virtual ~Window();

    virtual void run(std::function<void()> callback);

protected:
    GLFWwindow *_window;
};

} // namespace glfw
