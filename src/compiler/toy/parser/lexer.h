/*
 * lexer.h
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年4月1日 Author: menmen
 */

#ifndef PARSER_LEXER_H_
#define PARSER_LEXER_H_
#include <string>

enum Token : int {
  NUMBER_KEYWORD,
  VOID_KEYWORD,
  EXTERN_KEYWORD,
  IF_KEYWORD,
  FOR_KEYWORD,
  ELSE_KEYWORD,
  RETUEN_KEYWORD,

  CLASS_KEYWORD,
  PUBLIC_KEYWORD,
  PRIVATE_KEYWORD,

  IDENTIFIER_TOKEN,
  NUMBERLITERL_TOKEN,
  STRINGLITERL_TOKEN,
  CHARLITERL_TOKEN,

  OPENBRACE_TOKEN,
  CLOSEBRACE_TOKEN,
  OPENPAREN_TOKEN,
  CLOSEPAREN_TOKEN,
  SEMICOLON_TOKEN,
  COMMA_TOKEN,
  COLON_TOKEN,
  COLONCOLON_TOKEN,
  EQUALS_TOKEN,
  PLUS_TOKEN,
  MINUS_TOKEN,
  ASTERISK_TOKEN,
  SLASH_TOKEN,
  PLUSPLUS_TOKEN,
  MINUSMINUS_TOKEN,
  LESSTHAN_TOKEN,
  GREATERTHAN_TOKEN,
  LESSTHANEQUALS_TOKEN,
  GREATERTHANEQUALS_TOKEN,
  AND_TOKEN,
  OR_TOKEN,
  EOF_TOKEN
};

struct SourceLocation {
  int Line;
  int Col;
};

class Lexer {
 public:
  Lexer() : index_(-1), lex_loc_({1, 0}) {}
  void SetSource(std::string path);
  std::string GetTokenName(int Tok);
  int GetToken();
  void DumpLexer();
  double GetNumberValue() { return number_value_; }
  double GetCharValue() { return char_value_; }
  std::string GetIdentifer() { return identifier_str_; }

 private:
  int advance();
  bool IsNeedSkip(int last_char);
  bool IsIdentifierNondigit(int last_char);
  bool IsIdentifierNondigitOrDigit(int last_char);

  std::string source_;
  int index_;
  SourceLocation cur_loc_;
  SourceLocation lex_loc_;
  std::string identifier_str_;
  double number_value_;
  double char_value_;
};

#endif /* PARSER_LEXER_H_ */
