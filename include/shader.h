#pragma once

#include <string>
#include <unordered_map>

class Shader
{
public:
    Shader(std::string const &vertex_shader_path, std::string const &fragment_shader_path);
    ~Shader();

    void bind() const;
    void unbind() const;

    void set_uniform_4f(std::string const &name, float f1, float f2, float f3, float f4);
    void set_uniform_1f(std::string const &name, float value);
    void set_uniform_1i(std::string const &name, int value);

private:
    std::string _vertex_shader_path;
    std::string _fragment_shader_path;
    unsigned int _renderer_id;
    std::unordered_map<std::string, int> _uniform_location_cache;

    int get_uniform_location(std::string const &name);
    unsigned int create_shader(std::string const& vertex_shader, std::string const& fragment_shader);
    unsigned int compile_shader(unsigned int type, std::string const& source);
};
