#include <iostream>
#include <GL/glew.h>

#include "imgui_window.h"
#include "imgui/imgui.h"

#include "renderer.h"

#include "example.h"
#include "background_color_example.h"
#include "shape_example.h"
#include "multiple_objects_example.h"

#include <memory>
#include <vector>

int main()
{
    unsigned int const width = 640;
    unsigned int const height = 480;
    imgui::Window window(width, height, "Demo");

    int current_example_id = 0;
    int last_example_id = -1;

    std::unique_ptr<Example> current_example;
    Renderer renderer;

    window.run([&]() {
        renderer.clear();
        {
            ImGui::Begin("Demo");
            ImGui::RadioButton("Background", &current_example_id, 0);
            ImGui::RadioButton("Shapes", &current_example_id, 1);
            ImGui::RadioButton("Multiple objects", &current_example_id, 2);

            if (current_example_id != last_example_id) {
                if (current_example_id == 0) {
                    current_example = std::make_unique<BackgroundColorExample>();
                } else if (current_example_id == 1) {
                    current_example = std::make_unique<ShapeExample>(width, height);
                } else if (current_example_id == 2) {
                    current_example = std::make_unique<MultipleObjectsExample>(width, height);
                }
                last_example_id = current_example_id;
            }
            current_example->show_example(renderer);

            ImGui::Text("Current example: %s", current_example->get_name().c_str());
            ImGui::Text("Example options:");
            current_example->show_options();

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
    });
}
