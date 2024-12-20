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
  // Private Functions
  void Parser::constStatement() {
    currentToken == lexer.nextToken();; // consume "const"
    if (currentToken.type != Token::IDENTIFIER) {
      error("Expected identifier after 'const'");
    }
    std::string varName = currentToken.value;

    currentToken = lexer.nextToken(); // consume identifier
    if (currentToken.type != Token::ASSIGNMENT) {
      error("Expected '=' after identifier");
    }

    currentToken = lexer.nextToken(); // consume '='
    if (currentToken.type != Token::INTEGER) {
      error("Expected integer after '='");
    }
    int value = std::stoi(currentToken.value);

    currentToken = lexer.nextToken(); // consume integer
    if (currentToken.type != Token::SEMICOLON) {
      error("Expected ';' after expression");
    }

    variables[varName] = value;
    std::cout << "Variable " << varName << " assigned value " << value << std::endl;
  }

  void Parser::printStatement() {
    currentToken = lexer.nextToken(); // consume "print"
    if (currentToken.type != Token::IDENTIFIER) {
      error("Expected identifier after 'print'");
    }
    std::string varName = currentToken.value;

    currentToken = lexer.nextToken(); // consume identifier
    if (currentToken.type != Token::SEMICOLON) {
      error("Expected ';' after expression");
    }

    if (variables.find(varName) == variables.end()) {
      error("Variable not found");
    }
    std::cout << "Print: " << variables[varName] << std::endl;
  }

   void error(const std::string &message) {
     std::cerr << "Error: " << message << std::endl;
     exit(1);
   }
}
