/*
 * lexer.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年4月1日 Author: menmen
 */
#include "lexer.h"

#include <cctype>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

std::string Lexer::GetTokenName(int token) {
  switch (token) {
#define XX(name) \
  case name:     \
    return #name;

    XX(NUMBER_KEYWORD);
    XX(VOID_KEYWORD);
    XX(EXTERN_KEYWORD);
    XX(IF_KEYWORD);
    XX(FOR_KEYWORD);
    XX(ELSE_KEYWORD);
    XX(RETUEN_KEYWORD);

    XX(CLASS_KEYWORD);
    XX(PUBLIC_KEYWORD);
    XX(PRIVATE_KEYWORD);

    XX(IDENTIFIER_TOKEN);
    XX(NUMBERLITERL_TOKEN);
    XX(STRINGLITERL_TOKEN);
    XX(CHARLITERL_TOKEN);

    XX(OPENBRACE_TOKEN);
    XX(CLOSEBRACE_TOKEN);
    XX(OPENPAREN_TOKEN);
    XX(CLOSEPAREN_TOKEN);
    XX(SEMICOLON_TOKEN);
    XX(COMMA_TOKEN);
    XX(COLON_TOKEN);
    XX(COLONCOLON_TOKEN);
    XX(EQUALS_TOKEN);
    XX(PLUS_TOKEN);
    XX(MINUS_TOKEN);
    XX(ASTERISK_TOKEN);
    XX(SLASH_TOKEN);
    XX(PLUSPLUS_TOKEN);
    XX(MINUSMINUS_TOKEN);
    XX(LESSTHAN_TOKEN);
    XX(GREATERTHAN_TOKEN);
    XX(LESSTHANEQUALS_TOKEN);
    XX(GREATERTHANEQUALS_TOKEN);
    XX(AND_TOKEN);
    XX(OR_TOKEN);
    XX(EOF_TOKEN);
#undef XX
    default:
      return "UNKNOW";
  }
}

void Lexer::SetSource(std::string path) {
  std::ifstream in(path);
  if (!in.is_open()) {
    std::cout << "Error opening file!" << std::endl;
  }
  std::stringstream ss;
  ss << in.rdbuf();
  this->source_ = ss.str();
}

void Lexer::DumpLexer() {
  SetSource("test.toy");
  int token = EOF_TOKEN;
  do {
    token = GetToken();
    std::cout << GetTokenName(token) << std::endl;
  } while(token != EOF_TOKEN && token != EOF_TOKEN);
}

int Lexer::advance() {
  index_++;
  if (index_ == source_.length()) {
    return EOF;
  }
  int last_char = source_[index_];

  if (last_char == '\n' || last_char == '\r') {
    lex_loc_.Line++;
    lex_loc_.Col = 0;
  } else {
    lex_loc_.Col++;
  }

  return last_char;
}

/// [ \t\nEOF]
bool Lexer::IsNeedSkip(int last_char) {
  if (last_char == ' ' || last_char == '\t' || last_char == '\n') {
    return true;
  }
  return false;
}

bool Lexer::IsIdentifierNondigit(int last_char) {
  return isalpha(last_char) || (last_char == '_');
}

bool Lexer::IsIdentifierNondigitOrDigit(int last_char) {
  return isalnum(last_char) || (last_char == '_');
}

int Lexer::GetToken() {
  static int last_char = ' ';
  while (IsNeedSkip(last_char)) {
    last_char = advance();
  }

  cur_loc_ = lex_loc_;

  /**
   * Identifier: [a-zA-Z_]([a-zA-Z_] | [0-9])*
   * Keyword
   */
  if (IsIdentifierNondigit(last_char)) {
    identifier_str_ = last_char;
    last_char = advance();
    while (IsIdentifierNondigitOrDigit(last_char)) {
      identifier_str_ += last_char;
      last_char = advance();
    }
    if (identifier_str_ == "number") return NUMBER_KEYWORD;
    if (identifier_str_ == "void") return VOID_KEYWORD;
    if (identifier_str_ == "extern") return EXTERN_KEYWORD;
    if (identifier_str_ == "if") return IF_KEYWORD;
    if (identifier_str_ == "for") return FOR_KEYWORD;
    if (identifier_str_ == "else") return ELSE_KEYWORD;
    if (identifier_str_ == "return") return RETUEN_KEYWORD;
    if (identifier_str_ == "class") return CLASS_KEYWORD;
    if (identifier_str_ == "public") return PUBLIC_KEYWORD;
    if (identifier_str_ == "private") return PRIVATE_KEYWORD;
    return IDENTIFIER_TOKEN;
  }

  /// NumberLiteral: [0-9.]+
  if (isdigit(last_char) || last_char == '.') {
    std::string num_str;
    do {
      num_str += last_char;
      last_char = advance();
    } while (isdigit(last_char) || last_char == '.');
    number_value_ = strtod(num_str.c_str(), nullptr);
    return NUMBERLITERL_TOKEN;
  }

  /// operator
  switch (last_char) {
    case '{':
      last_char = advance();
      return OPENBRACE_TOKEN;
    case '}':
      last_char = advance();
      return CLOSEBRACE_TOKEN;
    case '(':
      last_char = advance();
      return OPENPAREN_TOKEN;
    case ')':
      last_char = advance();
      return CLOSEPAREN_TOKEN;
    case ';':
      last_char = advance();
      return SEMICOLON_TOKEN;
    case ',':
      last_char = advance();
      return COMMA_TOKEN;
    case ':':
      last_char = advance();
      if (last_char == ':') {
        last_char = advance();
        return COLONCOLON_TOKEN;
      }
      return COLON_TOKEN;
    case '=':
      last_char = advance();
      return EQUALS_TOKEN;
    case '+':
      last_char = advance();
      if (last_char == '+') {
        last_char = advance();
        return PLUSPLUS_TOKEN;
      }
      return PLUS_TOKEN;
    case '-':
      last_char = advance();
      if (last_char == '-') {
        last_char = advance();
        return MINUSMINUS_TOKEN;
      }
      return MINUS_TOKEN;
    case '*':
      last_char = advance();
      return ASTERISK_TOKEN;
    case '/':
      last_char = advance();
      /// SingleLineComment: '//' (~[\n])*
      if(last_char == '/') {
        do {
          last_char = advance();
        } while (last_char != '\n' && last_char != EOF);
        if (last_char != EOF) return GetToken();
      }
      return SLASH_TOKEN;
    case '<':
      last_char = advance();
      if (last_char == '=') {
        last_char = advance();
        return LESSTHANEQUALS_TOKEN;
      }
      return LESSTHAN_TOKEN;
    case '>':
      last_char = advance();
      if (last_char == '=') {
        last_char = advance();
        return GREATERTHANEQUALS_TOKEN;
      }
      return GREATERTHAN_TOKEN;
    case '&':
      last_char = advance();
      if (last_char == '&') {
        last_char = advance();
        return AND_TOKEN;
      }
      break;
    case '|':
      if (last_char == '|') {
        last_char = advance();
        return OR_TOKEN;
      }
      break;
    default:
      break;
  }

  /// CharLiteral: '\''('\\\n' | '\\\t' )'\''
  if (last_char == '\'') {
    std::string escape_str;
    do {
      last_char = advance();
      if(last_char == '\'') {
        last_char = advance();
        break;
      }
      escape_str += last_char;
    } while (last_char != EOF);
    if(escape_str == "\\n") {
      char_value_ = '\n';
      return CHARLITERL_TOKEN;
    }
    if(escape_str == "\\t") {
      char_value_ = '\t';
      return CHARLITERL_TOKEN;
    }
    if(escape_str.size() == 1) {
      char_value_ = escape_str[0];
      return CHARLITERL_TOKEN;
    }
  }
  if (last_char == EOF) return EOF_TOKEN;

  last_char = advance();
  return -1;
}
