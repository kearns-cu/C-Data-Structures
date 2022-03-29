/**
 * @file checker.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header file for checker class
 */

#ifndef CHECKER_H
#define CHECKER_H

#include "AStack.h"
#include <string>

using namespace std;

class checker{
private:
    AStack<char>* arrStack;
    bool error;
    int line;
    string FileName;
    char errChar;
    char charHolder;
public:
    checker();
    ~checker();
    bool checkFile(string fileName);
    void checkIfOpener(char c);
    bool checkError(char charHolder, char c);
    char findOppositeChar(char c);
};

#endif
