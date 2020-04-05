#pragma once

#include <functional>

class GLFWwindow;

class Window
{
public:
    Window(unsigned int width, unsigned int height, std::string const &title);
    ~Window();

    void run(std::function<void()> callback);
private:
    GLFWwindow *_window;
};

