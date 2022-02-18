#ifndef PARSER_H
#define PARSER_H
#include <string>
using namespace std;

class Parser{
private:
  std::string inputString;
  std::string outputSummary;
public:
  Parser();
  Parser(std::string input);
  ~Parser();
  static string count(string x);
  virtual void printToFile(string fileName);
  string getSummary();
};

#endif
