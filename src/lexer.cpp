#include <cctype>
#include "lexer.h"

namespace pygo {
  TokenInfo Lexer::nextToken() {
    skipWhitespace();

    if (index >= source.size()) return {Token::END, ""};

    char current = source[index];

    if (std::isalpha(current)) {
      return identifierOrKeyword();
    } else if (std::isdigit()) {
      return integer();
    } else if (current == '=') {
      index++;
      return {Token::ASSIGNMENT, "="};
    } else if (current == ';') {
      index++;
      return {Token::SEMICOLON, ";"};
    } else if (current == 'p'&& source.substr(index, 5) == "print") {
      index += 5;
      return {Token::PRINT, "print"};
    }

    return {Token::UNKNOWN, ""};
  }

  // Private functions
  void Lexer::skipWhitespace() {
    while (index < source.size() && std::isspace(source[index])) {
      index++;
    }
  }

  TokenInfo Lexer::identifierOrKeyword() {
    size_t start = index;
    while (index < source.size() && std::isalnum(source[index])) {
      index++;
    }
    std::string value = source.substr(start, index - start);
    if (value == "const") {
      return {Token::CONST, value};
    }
    return {Token::IDENTIFIER, value};
  }

  TokenInfo Lexer::integer() {
    size_t start = index;
    while (index < source.size() && std::isdigit(source[index])) {
      index++;
    }
    return {Token::INTEGER, source.substr(start, index - start)};
  }
}
