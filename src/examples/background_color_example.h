#pragma once

#include "example.h"

#include <glm/glm/glm.hpp>

class BackgroundColorExample : public Example
{
public:
    BackgroundColorExample();
    virtual ~BackgroundColorExample();

    virtual void show_options() override;
    virtual void show_example(Renderer const& renderer) override;
    virtual std::string get_name() const override;

private:
    glm::vec4 _colors;
};
