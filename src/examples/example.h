#pragma once

#include <string>

#include "renderer.h"

class Example
{
public:
    virtual ~Example() { };
    virtual void show_options() = 0;
    virtual void show_example(Renderer const& renderer) = 0;
    virtual std::string get_name() const = 0;
};

