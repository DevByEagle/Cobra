#ifndef PARSER_H
#define PARSER_H

#include <unordered_map>
#include "lexer.h"

namespace pygo {
  class Parser {
  public:
    Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.nextToken()) {}

    void parse();
  private:
    void constStatement();
    void printStatement();
    void error(const std::string &message);

    Lexer& lexer;
    TokenInfo currentToken;
    std::unordered_map<std::string, int> variables;
  };
}

#endif // PARSER_H
