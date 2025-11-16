#include "../includes/helper.h"
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>

int helper_string_int(std::string string) {

  int num = 0;
  try {
    num = std::stoi(string);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error converting string to int: " << e.what() << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: Value out of range for int: " << e.what() << std::endl;
  }

  return num;
}

std::string helper_decimal_string(int decimal) {
  std::bitset<15> binary(decimal);
  return binary.to_string();
};

void helper_append_file(std::string binary) {
  std::ofstream outputFile;
  outputFile.open("final.hack", std::ios::app);
  if (outputFile.is_open()) {
    outputFile << binary << std::endl;
    outputFile.close();
  } else {
    std::cerr << "Error opening file for appending." << std::endl;
  }
}

int helper_delimiter_pos(const std::string &line, char delimiter) {
  int pos = line.find(delimiter);
  if (pos == std::string::npos) {
    return 0;
  };
  return pos;
};
