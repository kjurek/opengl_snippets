#pragma once

#include <string>

void create_window(int argc,
                   char **argv,
                   unsigned width = 1024,
                   unsigned height = 768,
                   std::string const &title = "Window");

std::string read_file(std::string const &path);

unsigned int compile_shader(unsigned int type, std::string const &src);

unsigned int create_shader(std::string const &vertex_shader, std::string const &fragment_shader);
