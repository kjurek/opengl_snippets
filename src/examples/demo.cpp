#include <iostream>
#include <GL/glew.h>

#include "imgui_window.h"
#include "imgui/imgui.h"

#include "example.h"
#include "clear_color_example.h"
#include "triangle_example.h"
#include "square_example.h"
#include "texture_example.h"

#include <memory>

int main()
{
    unsigned int const width = 640;
    unsigned int const height = 480;
    imgui::Window window(width, height, "Demo");

    int current_example_id = 0;
    int last_example_id = -1;
    std::unique_ptr<Example> current_example;

    window.run([&]() {
        glClear(GL_COLOR_BUFFER_BIT);
        {
            ImGui::Begin("Demo");
            ImGui::RadioButton("Clear Color", &current_example_id, 0);
            ImGui::RadioButton("Triangle", &current_example_id, 1);
            ImGui::RadioButton("Square", &current_example_id, 2);
            ImGui::RadioButton("Texture", &current_example_id, 3);

            if (current_example_id != last_example_id) {
                switch (current_example_id) {
                case 0:
                    current_example = std::make_unique<ClearColorExample>();
                    break;
                case 1:
                    current_example = std::make_unique<TriangleExample>();
                    break;
                case 2:
                    current_example = std::make_unique<SquareExample>();
                    break;
                case 3:
                    current_example = std::make_unique<TextureExample>();
                    break;
                }
                last_example_id = current_example_id;
            }

            current_example->show_example();

            ImGui::Text("Current example: %s", current_example->get_name().c_str());
            ImGui::Text("Example options:");
            current_example->show_options();

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();
        }
    });
}
