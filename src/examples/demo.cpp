#include <iostream>
#include <GL/glew.h>

#include "imgui_window.h"
#include "imgui/imgui.h"

#include "renderer.h"

#include "example.h"
#include "background_color_example.h"
#include "shape_example.h"

#include <memory>
#include <vector>

int main()
{
    unsigned int const width = 640;
    unsigned int const height = 480;
    imgui::Window window(width, height, "Demo");

    int current_example_id = 0;
    std::vector<std::unique_ptr<Example>> examples;
    examples.push_back(std::make_unique<BackgroundColorExample>());
    examples.push_back(std::make_unique<ShapeExample>(width, height));

    Renderer renderer;

    window.run([&]() {
        renderer.clear();
        {
            ImGui::Begin("Demo");
            for (size_t i = 0; i < examples.size(); ++i)
            {
                ImGui::RadioButton(examples[i]->get_name().c_str(), &current_example_id, i);
            }

            examples[current_example_id]->show_example(renderer);

            ImGui::Text("Current example: %s", examples[current_example_id]->get_name().c_str());
            ImGui::Text("Example options:");
            examples[current_example_id]->show_options();

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
    });
}
