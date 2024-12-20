#ifndef LEXER_H
#define LEXER_H

#include <cstddef>
#include <string>

namespace pygo {
  enum class Token {
    CONST,
    IDENTIFIER,
    INTEGER,
    ASSIGNMENT,
    SEMICOLON,
    PRINT,
    END,
    UNKNOWN
  };

  struct TokenInfo {
    Token type;
    std::string value;
  };

  class Lexer {
  public:
    Lexer(const std::string& src) : source(src), index(0) {}

    TokenInfo nextToken();
  private:
    void skipWhitespace();
    TokenInfo identifierOrKeyword();
    TokenInfo integer();

    std::string source;
    size_t index;
  };
}

#endif // LEXER_H
