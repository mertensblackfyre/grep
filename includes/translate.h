#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "helper.h"
#include "parser.h"
#include <bitset>
#include <iostream>

class Translate {

public:
  inline std::string translate_a_instruc(const std::string &parsed_string);
};
std::string Translate::translate_a_instruc(const std::string &parsed_string) {
  std::string string_value = Parser::parse_A__(parsed_string);
  int number_value = helper_string_int(string_value);
  std::string binary_string = helper_decimal_string(number_value);
  std::string ss = binary_string.insert(0, "0");
  return ss;
};

#endif
