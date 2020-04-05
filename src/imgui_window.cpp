#include "imgui_window.h"

#include "imgui/imgui.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "imgui/examples/imgui_impl_glfw.h"
#include "imgui/examples/imgui_impl_opengl3.h"

#include <iostream>

namespace imgui {

Window::Window(unsigned int width, unsigned int height, const std::string &title)
    : glfw::Window(width, height, title)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(_window, true);
    ImGui_ImplOpenGL3_Init("#version 430");
    ImGui::StyleColorsDark();
}

Window::~Window()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Window::run(std::function<void()> callback)
{
    while (!glfwWindowShouldClose(_window)) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        callback();
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}

} // namespace imgui
