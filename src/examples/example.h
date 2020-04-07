#pragma once

#include <string>

class Example
{
public:
    virtual ~Example() { };
    virtual void show_options() = 0;
    virtual void show_example() = 0;
    virtual std::string get_name() const = 0;
};

