#pragma once

#include "example.h"

#include <glm/glm/glm.hpp>

class ClearColorExample : public Example
{
public:
    ClearColorExample();
    virtual ~ClearColorExample();

    virtual void show_options() override;
    virtual void show_example() override;
    virtual std::string get_name() const override;

private:
    glm::vec4 _colors;
};
