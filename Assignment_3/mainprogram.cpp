#include <iostream>
#include <string>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
using namespace std;


int main(){
  /*
  string fileIn;
  string fileOut;
  cout << "Enter the name of the file for input: ";
  cin >> fileIn;
  cout << "Enter the name for the output file: ";
  cin >> fileOut;
  FileProcessor();
  */
  /*
  Model* s = new Model();
  cout << s->translateSingleCharacter('d') << endl;
  cout << s->translateDoubleCharacter('d') << endl;
  cout << s->translateSingleCharacter('e') << endl;
  cout << s->translateDoubleCharacter('e') << endl;
  */
  /*
  Translator* t = new Translator();
  string toTranslate = "This is a test file.\n\
  I look at a Wall.\n\
  I took a walk;\n\
  to the park yesterday.\n";
  cout << t->translateEnglishSentence(toTranslate) << endl;
  */
  Translator* t = new Translator();
  FileProcessor* f = new FileProcessor();
  f->processFile("input.txt", "output.txt");

  //cout << t->translateEnglishWord("I took a walk to the"
  //" park yesterday") << endl;
  return 0;
}
