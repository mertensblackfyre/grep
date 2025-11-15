#ifndef PARSER_H
#define PARSER_H

#include <iostream>

class Parser {

public:
  static inline std::string parse_A__(const std::string &line);

  static inline std::string parse_C__(const std::string &line);
};

std::string Parser::parse_A__(const std::string &line) {
  return line.substr(1, line.size());
};

std::string Parser::parse_C__(const std::string &line) { return ""; };

#endif
