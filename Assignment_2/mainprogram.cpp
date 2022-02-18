#include <iostream>
#include <string>
#include "Parser.h"
using namespace std;


int main(){
  Parser();
  Parser* p1 = new Parser("CPSC350 is the best class!");
  string summary = p1->getSummary();
  cout << summary << endl;
  p1->printToFile("output.txt");
  return 0;
}
