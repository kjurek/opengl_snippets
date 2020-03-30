#pragma once

#include <string>

void create_window(int argc,
                   char **argv,
                   unsigned width = 1024,
                   unsigned height = 768,
                   std::string const &title = "Window");

std::string read_file(std::string const &path);
