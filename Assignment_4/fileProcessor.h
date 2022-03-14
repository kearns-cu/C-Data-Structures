/**
 * @file fileProcessor.h.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief processes files
 */

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "cell.h"
#include <string>

using namespace std;

class fileProcessor{
    private:
        cell** init;
        int rows, columns;
        string inputFile;
        string outputFile;

    public:
        // implement constructor and destructor
        fileProcessor();
        virtual ~fileProcessor();
        cell** processInputFile(string inputFile);
        void processOutputFile(string outputFile, string text);
        int getRows() const;
        void setRows(int rows);
        int getColumns() const;
        void setColumns(int columns);
};


#endif
