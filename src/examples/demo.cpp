#include <iostream>
#include <GL/glew.h>

#include "imgui_window.h"
#include "imgui/imgui.h"

#include "renderer.h"

#include "example.h"
#include "background_color_example.h"
#include "triangle_example.h"
#include "rectangle_example.h"
#include "texture_example.h"
#include "multiple_objects_example.h"
#include "batch_rendering_example.h"

#include <memory>
#include <vector>

struct ExampleOption
{
    std::string name;
    std::function<std::unique_ptr<Example>()> creator;
};

int main()
{
    unsigned int const width = 640;
    unsigned int const height = 480;
    imgui::Window window(width, height, "Demo");

    int current_example_id = 0;
    int last_example_id = -1;

    std::unique_ptr<Example> current_example;
    Renderer renderer;

    std::vector<ExampleOption> examples
        = {{"Background", []() { return std::make_unique<BackgroundColorExample>(); }},
           {"Triangle", [=]() { return std::make_unique<TriangleExample>(width, height); }},
           {"Rectangle", [=]() { return std::make_unique<RectangleExample>(width, height); }},
           {"Texture", [=]() { return std::make_unique<TextureExample>(width, height);}},
           {"Multiple objects", [=]() { return std::make_unique<MultipleObjectsExample>(width, height);}},
           {"Batch rendering", [=]() { return std::make_unique<BatchRenderingExample>(width, height);}}
    };

    window.run([&]() {
        renderer.clear();
        {
            ImGui::Begin("Demo");
            for (size_t i = 0; i < examples.size(); ++i) {
                ImGui::RadioButton(examples[i].name.c_str(), &current_example_id, i);
            }

            if (current_example_id != last_example_id) {
                current_example = examples[current_example_id].creator();
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
