/*
Translator.cpp
Inherits Model classes functions to translate words and sentences
*/
#include <iostream>
#include <string>
#include "Translator.h"
#include "Model.h"
#include <fstream>
using namespace std;

/*
Translator()
Translator's default constructor
*/
Translator::Translator(){

}

/*
Translator()
Translator's default destructor
*/
Translator::~Translator(){

}

/*
translateEnglishWord()
Takes a single word and translates each character to append to the return string
@param string word
@return string translated word is returned
*/
string Translator::translateEnglishWord(string word){
  string tutWord;
  word += "";
  Model* translator = new Model();
  for(int i = 0; i < word.length(); ++i){
    if(word[i] == word[i + 1]){
      tutWord.append(translator->translateDoubleCharacter(word[i]));
      i+=1;
    } else {
      tutWord.append(translator->translateSingleCharacter(word[i]));
    }
  }
  return tutWord;
}

string Translator::translateEnglishSentence(string sentence){
  string currWord = "";
  string tranSentence = "";
  for(int i = 0; i < sentence.size(); ++i){
    if(sentence[i] == ' '|| sentence[i] == '!' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == ';'){
      tranSentence += translateEnglishWord(currWord);
      currWord = "";
      tranSentence += sentence[i];
    } else {
      currWord += sentence[i];
    }
  }

  return tranSentence;
}
