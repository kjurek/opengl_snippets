#include "clear_color_example.h"

#include <GL/glew.h>

#include "imgui/imgui.h"

ClearColorExample::ClearColorExample()
    :   _colors(0.0f, 0.0f, 0.0f, 1.0f)
{

}

ClearColorExample::~ClearColorExample() {
    glClearColor(0, 0, 0, 1.0f);
}

void ClearColorExample::show_options() {
    ImGui::ColorEdit4("Colors", &_colors.r);
}

void ClearColorExample::show_example() {
    glClearColor(_colors.r, _colors.g, _colors.b, _colors.a);
}

std::string ClearColorExample::get_name() const
{
    return "Clear Color";
}
