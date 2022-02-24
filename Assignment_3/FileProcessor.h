#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <string>
using namespace std;

class FileProcessor{
private:
public:
  FileProcessor();
  ~FileProcessor();
  void processFile(string inputFile, string outputFile);
};

#endif
