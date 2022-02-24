#ifndef MODEL_H
#define MODEL_H
#include <string>
using namespace std;

class Model{
private:
  char m_tutChar;
public:
  Model();
  ~Model();
  string translateSingleCharacter(char charInput);
  string translateDoubleCharacter(char charInput);
};

#endif
