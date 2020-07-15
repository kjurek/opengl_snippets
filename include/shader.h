#pragma once

#include <string>
#include <unordered_map>

#include "glm/glm/glm.hpp"

class Shader
{
public:
    Shader(std::string const& vertex_shader_path, std::string const& fragment_shader_path);
    ~Shader();

    Shader(Shader const&) = delete;
    Shader& operator=(Shader const&) = delete;

    void bind() const;
    void unbind() const;

    int uniform_location(std::string const& name);

private:
    unsigned int _renderer_id;
    std::unordered_map<std::string, int> _uniform_location_cache;

    unsigned int create_shader(std::string const& vertex_shader, std::string const& fragment_shader);
    unsigned int compile_shader(unsigned int type, std::string const& source);
};
