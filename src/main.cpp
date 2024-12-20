#include <iostream>
#include "parser.h"
#include "lexer.h"

std::string readFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "USAGE: %s <file_to_compile>" << argv[0] << std::endl;
    std::exit(0);
  }

  std::string code = readFile(argv[1]);
  pygo::Lexer lexer(code);
  pygo::Parser parser(lexer);

  parser.parse();

  return 0;
}
