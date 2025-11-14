#ifndef PARSER_H
#define PARSER_H

#include <iostream>

class Parser {

public:
  static inline std::string parse_a_instruc(std::string line);
};

std::string Parser::parse_a_instruc(std::string line) {
  return line.substr(1, line.size());
};

#endif
