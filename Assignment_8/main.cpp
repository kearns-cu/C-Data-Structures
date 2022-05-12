/**
 * @file main.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief main program
 */
 #include <iostream>
 #include <string>
 #include "sortAlgos.h"

 using namespace std;

 int main(int argc, char** argv){

 		string mode = argv[1];
 		int number = atoi(argv[2]);
 		string filename = argv[3];
 		sortAlgos sort;
 		sort.run(mode, number, filename);

 		return 0;
 }
