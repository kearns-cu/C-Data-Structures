/*
FileProcessor.cpp
Take user defined input and writes translation to user defined output
*/

#include "FileProcessor.h"
#include "Translator.h"  // Since I create an object of the Translator class, I have to include the Translator header file here
#include <fstream>
#include <iostream>
using namespace std;

/*
FileProcessor()
FileProcessor's default constructor
*/
FileProcessor::FileProcessor(){

}

/*
FileProcessor()
FileProcessor's default destructor
*/
FileProcessor::~FileProcessor(){

}

/*
processFile()
File takes the names of the input and ouput files and then read/writes respectively
@param string inputName, string outputName
@return void
*/
void FileProcessor::processFile(string inputName, string outputName){
  // use fstream objects to read and write to files
  Translator transObject; // here you can use an object of the Translator class
  // for each line of the input file, call the Translator object's translateEnglishSentence function
    string singleLine;
    string translatedLine;
    ifstream inputStream;
    ofstream outputStream;

    inputStream.open(inputName);
    outputStream.open(outputName);
    if(inputStream.is_open()){
      while(getline(inputStream, singleLine)){
        translatedLine = transObject.translateEnglishSentence(singleLine);
        outputStream << translatedLine << endl;
      }
    }
    inputStream.close();
    outputStream.close();
}
