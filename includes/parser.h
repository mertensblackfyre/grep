#ifndef PARSER_H
#define PARSER_H

#include "helper.h"
#include <iostream>

struct C_Instruction {
  std::string dest{};
  std::string comp{};
  std::string jump{};
};

class Parser {

public:
  static inline std::string parse_A__(const std::string &line);
  static inline C_Instruction parse_C__(const std::string &line);
};

std::string Parser::parse_A__(const std::string &line) {
  return line.substr(1, line.size());
};

C_Instruction Parser::parse_C__(const std::string &line) {

  C_Instruction ins{"", "", ""};

  int equal_pos = helper_delimiter_pos(line, '=');
  int semicolon_pos = helper_delimiter_pos(line, ';');

  std::string dest_instruc = line.substr(0, equal_pos);
  std::string comp_instruc = line.substr(equal_pos, semicolon_pos);
  std::string jump_instruc = line.substr(semicolon_pos, line.size() - 1);


  std::cout << dest_instruc << std::endl;
  std::cout << comp_instruc << std::endl;
  std::cout << jump_instruc << std::endl;
  return ins;
};

#endif
