#pragma once

#include <functional>

#include "glfw_window.h"

namespace imgui {

class Window : glfw::Window
{
public:
    Window(unsigned int width, unsigned int height, std::string const &title);
    virtual ~Window();

    virtual void run(std::function<void()> callback) override;
};

} // namespace imgui
