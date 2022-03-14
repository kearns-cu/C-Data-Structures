/**
 * @file fileProcessor.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief processes files
 */

#include "fileProcessor.h"
#include "cell.h"
#include <fstream>

using namespace std;

// Default constructor.
fileProcessor::fileProcessor(){

}
// Destructor.
fileProcessor::~fileProcessor(){

}


/**
 * cell** fileProcessor::processInputFile(string inputName).
 * @breif - Creates 2d array of type cell.
 * @return cell**.
 * @param string inputName.
 */
cell** fileProcessor::processInputFile(string inputName){
    ifstream in_file;
    in_file.open(inputName);
    int columns;
    char t;
    in_file >> rows;
    in_file >> columns;

    rows+=2;
    columns+=2;
    init = new cell*[rows];
    for(int i = 0; i < rows; i++){
        init[i] = new cell[columns];
    }

    setRows(rows);
    setColumns(columns);

    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < columns-1; j++) {
            in_file >> t;
            if (t == 'x' || t == 'X') {
                init[i][j].isAlive(true);
            } else if (t == '-') {
                init[i][j].isAlive(false);
            } else {
              // Do nothing.
            }
        }
    }
    in_file.close();
    return init;

}

/**
 * int fileProcessor::getRows() const.
 * @breif - row accessor.
 * @return int rows.
 * @param n/a.
 */
int fileProcessor::getRows() const {
    return rows;
}

/**
 * void fileProcessor::setRows(int row).
 * @breif - rows mutator.
 * @return n/a.
 * @param int rows.
 */
void fileProcessor::setRows(int rows) {
    this->rows = rows;
}

/**
 * int fileProcessor::getColumns() const.
 * @breif - columns accessor.
 * @return int columns.
 * @param n/a.
 */
int fileProcessor::getColumns() const {
    return columns;
}

/**
 * void fileProcessor::setColumns(int columns).
 * @breif - columns mutator.
 * @return n/a.
 * @param int columns.
 */
void fileProcessor::setColumns(int columns) {
    this->columns = columns;
}

/**
 * void fileProcessor::processOutputFile(string outputName, string text).
 * @breif - Prints string to file.
 * @return n/a.
 * @param string outputName, string text.
 */
void fileProcessor::processOutputFile(string outputName, string text){
    // Wrting to file "outputName" (.txt).
    ofstream out_file;
    out_file.open(outputName);
    out_file << text << endl;
    out_file.close();
}
