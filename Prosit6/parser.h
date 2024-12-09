#pragma once

#include <iostream>
#include <stack>

#include "lexer.h"

using namespace std;

class Expression;

stack<Expression *> operators;
stack<int> operands;

class Expression {
public:
  virtual void interpret() = 0;
  virtual ~Expression() {}
};

class OpenExpression : public Expression {
  void interpret() { ; }
};

class UnaryOp : public Expression {
public:
  virtual int compute(int right) = 0;

  void interpret() override {
    int right = operands.top();  // Récupère la valeur située au sommet de la pile d'opérandes.
    operands.pop();  // Retire cette valeur de la pile après l'avoir récupérée.
    int result = compute(right);  // Effectue une opération sur la valeur extraite (c'est une fonction `compute` qui va être appliquée à la valeur récupérée).
    operands.push(result);  // Pousse le résultat de l'opération dans la pile des opérandes pour qu'il soit utilisé par les prochaines opérations.
  }
};

class MinusUnaryOp : public UnaryOp {
public:
  int compute(int right) override {
    return -right;  // Retourne le négatif de l'opérande (effectue une opération de soustraction unitaire).
  }

};

class PlusUnaryOp : public UnaryOp {
public:
  int compute(int right) override {
    return +right;  // Retourne le positif l'opérande (effectue une opération de plus unitaire).
  }

};

class BinaryOp : public Expression {
public:
  virtual int compute(int left, int right) = 0;

  void interpret() override {
    int right = operands.top();  // Récupère l'opérande de droite (top de la pile).
    operands.pop();  // Retire l'opérande de droite de la pile après l'avoir récupéré.
    int left = operands.top();  // Récupère l'opérande de gauche (nouveau top de la pile).
    operands.pop();  // Retire l'opérande de gauche de la pile après l'avoir récupéré.
    int result = compute(left, right);  // Effectue l'opération binaire entre l'opérande gauche et droit.
    operands.push(result);  // Pousse le résultat de l'opération dans la pile.

  }
};

class MinusBinaryOp : public BinaryOp {
public:
  int compute(int left, int right) override {
    return left - right;  // Effectue la soustraction entre l'opérande gauche et l'opérande droite.
  }
};

class PlusBinaryOp : public BinaryOp {
public:
  int compute(int left, int right) override {
    return left + right;  // Effectue l'addition entre l'opérande gauche et l'opérande droite.
  }
};

class StarBinaryOp : public BinaryOp {
public:
  int compute(int left, int right) override {
    return left * right;  // Effectue la multiplication entre l'opérande gauche et l'opérande droite.
  }
};

class DivBinaryOp : public BinaryOp {
public:
  int compute(int left, int right) override {
    return left / right;  // Effectue la division de l'opérande gauche par l'opérande droite.
  }
};


enum OperatorType { UNARY, BINARY, TERNARY };

class OperatorFactory {
public:
  static Expression *build(TokenType tokenType, OperatorType operatorType) {
    Expression *expr;
    switch (operatorType) {
    case OperatorType::UNARY:
      switch (tokenType) {
      case TokenType::PLUSOPERATOR:
        expr = new PlusUnaryOp();
        break;
      case TokenType::MINUSOPERATOR:
        expr = new MinusUnaryOp();
        break;
      default:
        throw new runtime_error("Unhandled unary operator.");
      }
      break;
    case OperatorType::BINARY:
      switch (tokenType) {
      case TokenType::PLUSOPERATOR:
        expr = new PlusBinaryOp();
        break;
      case TokenType::MINUSOPERATOR:
        expr = new MinusBinaryOp();
        break;
      case TokenType::STAROPERATOR:
        expr = new StarBinaryOp();
        break;
      case TokenType::SLASHOPERATOR:
        expr = new DivBinaryOp();
        break;
      default:
        throw new runtime_error("Unhandled binary operator.");
      }
      break;
    default:;
    }

    return expr;  // On retourne l'expression créée.

  }
};

/*
  La grammaire LL(1):

  BASE_EXP -> ( EXP ) |  LITERAL
  EXP -> BASE_EXP BINOP BASE_EXP | UNOP BASE_EXP
  BINOP -> - | + | * | /
  UNOP -> - | +
  LITERAL -> [0-9]+
*/

/*
  For the motivated one's, the following grammar handles the more complex cases
  of fully parenthesized infix arithmetic expressions. This grammar has
  specifically been designed to be "code tractable", meaning that solving
  special cases (such as ((1)) ) SHOULD be eased. E' -> E E -> ( H H -> G O ) H
  -> L I ) G -> U K G -> E I -> B F I -> '' O -> B F O -> '' K -> E K -> L F ->
  L F -> E U -> + U -> - B -> U B -> * B -> / L -> 1

  Can be tested on https://jsmachines.sourceforge.net/machines/ll1.html
*/

class ExtendedParser {
  vector<Token *> tokens;
  int idx;

public:
  ExtendedParser(vector<Token *> tokens) {
    this->tokens = tokens;

    reset();
  }

  Token *next() {
    if (idx < tokens.size()) {
      return tokens[idx++];
    }

    throw runtime_error("Syntax error.");
  }
  void rewind() { idx--; }
  void reset() { idx = 0; }
  int parse() {
    reset();

    consumeBaseExpression();

    return operands.top();
  }
  void consumeLeftParenthesis() {
    Token *curr = next();

    if (!curr->isType(TokenType::LPARENTHESIS)) {
      throw runtime_error("Expected opening parenthesis.");
    }
  }
  void consumeRightParenthesis() {
    Token *curr = next();

    if (!curr->isType(TokenType::RPARENTHESIS)) {
      throw runtime_error("Expected closing parenthesis.");
    }
  }
  bool consumeBinop() {
    Token *curr = next();

    if (curr->isType(TokenType::MINUSOPERATOR) ||
        curr->isType(TokenType::PLUSOPERATOR) ||
        curr->isType(TokenType::STAROPERATOR) ||
        curr->isType(TokenType::SLASHOPERATOR)) {
      Expression *expr;

      expr = OperatorFactory::build(curr->getType(), BINARY);  // Crée un opérateur binaire à partir du type du token courant
      operators.push(expr);  // Ajoute l'expression opérateur à la pile des opérateurs

      return true;
    }
    rewind();

    return false;
  }
  bool consumeUnop() {
    Token *curr = next();

    if (curr->isType(TokenType::MINUSOPERATOR) ||
        curr->isType(TokenType::PLUSOPERATOR)) {
      Expression *expr;

      expr = OperatorFactory::build(curr->getType(), UNARY); // Crée un opérateur unaire à partir du type du token courant
      operators.push(expr);  // Ajoute l'expression opérateur unaire à la pile des opérateurs

      return true;
    }
    rewind();

    return false;
  }
  bool consumeLitteral() {
    Token *curr = next();

    if (curr->isType(TokenType::INTEGER)) {
      operands.push(stoi(curr->getValue()));  // Convertit la valeur du token courant en entier et l'ajoute à la pile des opérandes

      return true;
    }
    rewind();

    return false;
  }
  void consumeBaseExpression() {
    if (!consumeLitteral()) {
      consumeLeftParenthesis();  // Consomme une parenthèse gauche '('
      consumeExpression();  // Consomme une expression qui peut être une sous-expression entre parenthèses
      consumeRightParenthesis(); // Consomme une parenthèse droite ')'

      solve();
    }
  }
  void consumeExpression() {
    if (!consumeUnop()) {
      consumeBaseExpression();
      consumeBinop();
    }

    consumeBaseExpression();
  }
  void solve() {
    Expression *expr;

    if (operators.size() >= 1) {
      expr = operators.top();
      operators.pop();

      expr->interpret();
      delete expr;
    } else
      throw runtime_error("Syntax error.");
  }
};

/* Poorly implemented parser :

class Parser {
public:
  void parse(vector<Token *> tokens) {
    Expression *expr;

    for (int i = 0; i < tokens.size(); ++i) {
      Token *curr = tokens[i];

      if (curr->isType(TokenType::LPARENTHESIS)) {
        operators.push(new OpenExpression());
        if (i + 1 < tokens.size()) {
          if (tokens[i + 1]->isOperator()) {
            curr = tokens[++i];

            expr = OperatorFactory::build(curr->getType(), OperatorType::UNARY);
            operators.push(expr);
          }
        } else
          throw new runtime_error("Expected token after opening parenthesis.");
      } else if (tokens[i]->isType(TokenType::INTEGER)) {
        operands.push(stoi(tokens[i]->getValue()));
      } else if (tokens[i]->isOperator()) {
        if (!(i - 1 > 0 && i + 1 < tokens.size() &&
              (tokens[i - 1]->isType(TokenType::INTEGER) ||
               tokens[i - 1]->isType(TokenType::RPARENTHESIS)) &&
              (tokens[i + 1]->isType(TokenType::INTEGER) ||
               tokens[i + 1]->isType(TokenType::LPARENTHESIS)))) {
          throw new runtime_error("Expected two operands for binary operator.");
        }

        expr =
            OperatorFactory::build(tokens[i]->getType(), OperatorType::BINARY);

        operators.push(expr);
      } else if (tokens[i]->isType(TokenType::RPARENTHESIS)) {
        if (operators.size() >= 2) {
          expr = operators.top();
          operators.pop();

          expr->interpret();
          delete expr;

          // pop left parenthesis
          expr = operators.top();
          operators.pop();

          delete expr;
        } else
          throw new runtime_error("Syntax error.");
      }
    }
    if (operators.size() != 0) {
      throw new runtime_error("Syntax error.");

      while (operators.size() != 0) {
        expr = operators.top();
        operators.pop();

        delete expr;
      }
    }

    cout << operands.top() << endl;
  }
};*/
