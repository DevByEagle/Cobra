#include "parser.h"

namespace pygo {
  void Parser::parse() {
    while (currentToken.type != Token::END) {
      if (currentToken.type == Token::CONST) {
        constStatement();
      } else if (currentToken.type == Token::PRINT) {
        printStatement();
      } else {
        error("Unexpected token");
      }
      currentToken == lexer.nextToken();
    }
  }
}
