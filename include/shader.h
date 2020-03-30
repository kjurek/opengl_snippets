#pragma once

#include <string>

class Shader
{
public:
    Shader(std::string const &vertex_shader_path, std::string const &fragment_shader_path);
    ~Shader();

    void bind() const;
    void unbind() const;

    void set_uniform_4f(std::string const &name, float f1, float f2, float f3, float f4);

private:
    std::string _vertex_shader_path;
    std::string _fragment_shader_path;
    unsigned int _renderer_id;

    int get_uniform_location(std::string const &name) const;
    unsigned int create_shader(std::string const& vertex_shader, std::string const& fragment_shader);
    unsigned int compile_shader(unsigned int type, std::string const& source);
};
