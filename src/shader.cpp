#include "shader.h"

#include <iostream>
#include <fstream>

#include <GL/glew.h>

namespace {

std::string read_file(std::string const& path)
{
    std::ifstream f(path);
    if (!f) {
        throw "Couldn't read file " + path;
    }
    return std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
}

}

Shader::Shader(std::string const& vertex_shader_path, std::string const& fragment_shader_path)
{
    auto vertex_shader = read_file(vertex_shader_path);
    auto fragment_shader = read_file(fragment_shader_path);
    _renderer_id = create_shader(vertex_shader, fragment_shader);
}

Shader::~Shader()
{
    if (_renderer_id)
    {
        glDeleteProgram(_renderer_id);
    }
}

Shader::Shader(Shader&& s) noexcept
{
    *this = std::move(s);
}

Shader& Shader::operator=(Shader&& s) noexcept
{
    if (this != &s)
    {
        if (_renderer_id)
        {
            glDeleteProgram(_renderer_id);
        }
        _renderer_id = s._renderer_id;
        _uniform_location_cache = std::move(s._uniform_location_cache);

        s._renderer_id = 0;
    }
    return *this;
}

void Shader::bind() const
{
    glUseProgram(_renderer_id);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

int Shader::uniform_location(std::string const& name)
{
    if (_uniform_location_cache.count(name)) {
        return _uniform_location_cache[name];
    }

    auto location = glGetUniformLocation(_renderer_id, name.c_str());
    if (location == -1) {
        std::cout << "Warning: uniform '" << name << "' doesn't exist" << std::endl;
    }
    _uniform_location_cache[name] = location;

    return location;
}

unsigned int Shader::create_shader(std::string const& vertex_shader, std::string const& fragment_shader)
{
    auto program = glCreateProgram();
    auto vs = compile_shader(GL_VERTEX_SHADER, vertex_shader);
    auto fs = compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

unsigned int Shader::compile_shader(unsigned int type, std::string const& source)
{
    auto id = glCreateShader(type);
    auto cstr = source.c_str();
    glShaderSource(id, 1, &cstr, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = static_cast<char *>(alloca(length * sizeof(char)));
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << "Failed to compile shader" << std::endl;
        std::cerr << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}
