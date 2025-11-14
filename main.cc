#include "includes/helper.h"
#include "includes/parser.h"
#include "includes/translate.h"
#include <fstream>
#include <iostream> // For console output
#include <string>   // For reading lines into a string

int main() {

  Parser parse;
  Translate t;

  std::ifstream inputFile("m.asm");
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    if (line.size() < 1) {
      continue;
    } else if (line.substr(0, 1) == "//") {
      continue;
    } else if (line[0] == '@') {
      std::string final_output = t.translate_a_instruc(line);
      helper_append_file(final_output);
    }
  }
}
