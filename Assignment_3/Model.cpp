/*
Model.cpp
Tranaslates single characters and double characters based on Tutnese word
*/
#include <iostream>
#include <string>
#include "Model.h"
#include <fstream>
using namespace std;

/*
Model()
Model's default constructor
*/
Model::Model(){

}

/*
Model()
Model's default destructor
*/
Model::~Model(){
}

/*
translateSingleCharacter()
Takes a single character and translates it
@param char input
@return string translated character
*/
string Model::translateSingleCharacter(char input){
  switch(input){
    case 'B':
    return "Bub";
    break;

    case 'b':
    return "bub";
    break;

    case 'C':
    return "Cash";
    break;

    case 'c':
    return "cash";
    break;

    case 'D':
    return "Dud";
    break;

    case 'd':
    return "dud";
    break;

    case 'F':
    return "Fuf";
    break;

    case 'f':
    return "fuf";
    break;

    case 'G':
    return "gug";
    break;

    case 'H':
    return "Hash";
    break;

    case 'h':
    return "hash";
    break;

    case 'J':
    return "Jay";
    break;

    case 'j':
    return "jay";
    break;

    case 'K':
    return "Kuck";
    break;

    case 'k':
    return "kuck";
    break;

    case 'L':
    return "Lul";
    break;

    case 'l':
    return "lul";
    break;

    case 'M':
    return "Mum";
    break;

    case 'm':
    return "mum";
    break;

    case 'N':
    return "Num";
    break;

    case 'n':
    return "num";
    break;

    case 'P':
    return "Pub";
    break;

    case 'p':
    return "pub";
    break;

    case 'Q':
    return "Quack";
    break;

    case 'q':
    return "quack";
    break;

    case 'R':
    return "Rug";
    break;

    case 'r':
    return "rug";
    break;

    case 'S':
    return "Sus";
    break;

    case 's':
    return "sus";
    break;

    case 'T':
    return "Tut";
    break;

    case 't':
    return "tut";
    break;

    case 'V':
    return "Vuv";
    break;

    case 'v':
    return "vuv";
    break;

    case 'W':
    return "Wack";
    break;

    case 'w':
    return "wack";
    break;

    case 'X':
    return "Ex";
    break;

    case 'x':
    return "ex";
    break;

    case 'Y':
    return "Yub";
    break;

    case 'y':
    return "yub";
    break;

    case 'Z':
    return "Zub";
    break;

    case 'z':
    return "zub";
    break;

    default:
    string s(1, input);
    return s;
    break;
  }
}

/*
translateDoubleCharacter()
Takes a double character and translates it
@param char input
@return string translated double character
*/
string Model::translateDoubleCharacter(char input){
  bool isVowel = false;
  string returnString;
  Model* singleChar = new Model();
  isVowel = (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u' ||
      input == 'A' || input == 'E' || input == 'I' || input == 'O' || input == 'U' );
  if(isVowel){
    returnString = "squat";
    returnString.push_back(input);
    return returnString;
  } else {
    returnString = "squa";
    string endChar = translateSingleCharacter(input);
    returnString += endChar;
    return returnString;
  }
}
