/**
 * @file main.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief main program
 */
#include "checker.h"
#include "AStack.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    checker c;
    string f;
    if(argc > 1){
      f = (argv[1]);
    }
    string answer = "yes";
    if(f != ""){
      c.checkFile(f);
    }
    do{
        cout << "Would you like to try another file? (yes or no)" << endl;
        cin >> answer;
        if(answer == "no"){
          break;
        }
        cout << "Please enter the path of the file you would like to check for errors: " << endl;
        cin >> f;
        c.checkFile(f);

    }while(answer != "no");

    return 0;
}
