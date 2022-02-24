#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <string>
using namespace std;

class Translator{
private:
public:
  Translator();
  ~Translator();
  string translateEnglishWord(string wordInput);
  string translateEnglishSentence(string sentenceInput);
};

#endif
