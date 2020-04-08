#include "background_color_example.h"

#include <GL/glew.h>

#include "imgui/imgui.h"

BackgroundColorExample::BackgroundColorExample()
    :   _colors(0.0f, 0.0f, 0.0f, 1.0f)
{

}

BackgroundColorExample::~BackgroundColorExample() {
    glClearColor(0, 0, 0, 1.0f);
}

void BackgroundColorExample::show_options() {
    ImGui::ColorEdit4("Colors", &_colors.r);
}

void BackgroundColorExample::show_example(Renderer const& renderer) {
    glClearColor(_colors.r, _colors.g, _colors.b, _colors.a);
}

std::string BackgroundColorExample::get_name() const
{
    return "Clear Color";
}
