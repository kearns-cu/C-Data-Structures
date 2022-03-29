/**
 * @file checker.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief gets a file and utilizes stack to check for balanced delimiters
 */

#include "AStack.h"
#include "checker.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * checker::checker()
 * @brief declares a new stack of size five and initializes the line to 0
 * @brief default constructor
 * @param n/a
 */
checker::checker(){

    arrStack = new AStack<char>(5);
    line = 0;
}

/**
 * checker::~checker()
 * @brief default destructor
 * @param n/a
 */
checker::~checker(){

}

/**
 * bool checker::checkFile(string fileName)
 * @brief: takes input file and reads line for line
 *         while utilizing stack and other methods to check for balanced delimiters
 * @return bool of whether there is an error occurance
 * @param string fileName, name of the input file
 */
bool checker::checkFile(string fileName){
    error = false;
    ifstream fileIn;
    fileIn.open(fileName);
    string newLine;
    while(getline(fileIn, newLine) && error != true){

        line++;

        if(newLine[0] == *"/" && newLine[1] == *"/"){
            error = true;
        }else{
          for(int i = 0; i<newLine.length(); i++){
              checkIfOpener(newLine[i]);
              errChar = newLine[i];
              if(error == true){
                  break;
              }
          }
        }
    }
    if(!(arrStack->isEmpty())){
      error = true;
    }
    if(error == true){
      if(findOppositeChar(charHolder) == errChar){
        cout << "Line " << line << ": expected nothing and found " << errChar << endl;
      }else{
        cout << "Line " << line << ": expected " << findOppositeChar(charHolder) << " and found " << errChar << endl;
      }

    }

    if(error == false){
        cout << "This program has CORRECT syntax." << endl;

    }
    fileIn.close();
    //if not empty then check for edge case
    //hanging bracket
    if(error == false){
      return false;
    }else{
      return true;
    }
}

/**
 * void checker::checkIfOpener(char c)
 * @brief switch statement which decides between which delimiter should be pushed or popped from the stack
 * @return void
 * @param char c, character that is checked
 */
void checker::checkIfOpener(char c){
    switch(c){
        case '(':
            arrStack->push(c);
            break;
        case '{':
            arrStack->push(c);
            break;
        case '[':
            arrStack->push(c);
            break;
        case ')':
            if(arrStack->isEmpty()){
                error = true;
                break;
            }else{
                charHolder = arrStack->pop();
                error = checkError(charHolder, c);
                break;
            }
        case '}':
            if(arrStack->isEmpty()){
                error = true;
                break;
            }else{
                charHolder = arrStack->pop();
                error = checkError(charHolder, c);
                break;
            }
        case ']':
            if(arrStack->isEmpty()){
                error = true;
                break;
            }else{
                charHolder = arrStack->pop();
                error = checkError(charHolder, c);
                break;
            }
        default:
            break;
    }
}

/**
 * bool checker::checkError(char charHolder, char c)
 * @brief checks whether the char currently found matches the char popped off the stack
 * @return bool
 * @param char c, char charHolder
 */
bool checker::checkError(char charHolder, char c){
   return(findOppositeChar(c) != charHolder);
}

/**
 * char checker::findOppositeChar(char c)
 * @brief returns the complementary delimiter given a char delimiter
 * @return char
 * @param char c
 */
char checker::findOppositeChar(char c){
    switch(c){
        case '(':
            return ')';
        case '{':
            return '}';
        case '[':
            return ']';
        case ')':
            return '(';
        case '}':
            return '{';
        case ']':
            return '[';
        default:
            return ' ';
    }
}
