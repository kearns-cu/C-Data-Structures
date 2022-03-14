/**
 * @file board.cpp.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief board for game of life.
 */

#include "board.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Default Constructor.
board::board() {

}
/**
 * void board::Initialize(cell** i_cl, int rows, int columns, int bound, double percent).
 * @breif - creates initial grid (gen 0).
 * @return n/a.
 * @param cell** i_cl, int rows, int columns, int bound, double percent.
 */
void board::Initialize(cell** i_cl, int rows, int columns, int bound, double percent){
    this->rows = rows;
    this->columns = columns;

    currGrid = new cell*[rows];
    secondaryGrid = new cell*[rows];

    for(int i = 0; i < rows; i++){
        currGrid[i] = new cell[columns];
        secondaryGrid[i] = new cell[columns];
    }

                string ret = "";
    switch (bound) {
        case 0:
            double ra;
            srand( (unsigned)time( NULL ) ); // random
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {

                    ra = (float) rand()/RAND_MAX; // random
                    if ((percent) >= ra){
                        currGrid[i][j].isAlive(true);
                    } else {
                        currGrid[i][j].isAlive(false);
                    }
                }
            }
        break;

        case 1:
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (i_cl[i][j].isAlive() == true){
                        currGrid[i][j].isAlive(true);
                    } else {
                        currGrid[i][j].isAlive(false);
                    }
                }
            }
        break;
    }

}
// Destructor.
board::~board() {
    for(int i = 0; i < rows; i++){
        delete[] currGrid[i];
        delete[] secondaryGrid[i];
    }
    delete[] currGrid;
    delete[] secondaryGrid;
}
/**
 * void board::setRows(int row).
 * @breif - rows mutator.
 * @return n/a.
 * @param int rows.
 */
void board::setRows(int rows) {
    this->rows = rows;
}
/**
 * void board::setRows(int row).
 * @breif - rows mutator.
 * @return n/a.
 * @param int rows.
 */
void board::setColumns(int columns) {
    this->columns = columns;
}

/**
 * void board::swap().
 * @breif - swaps currGrid and secondaryGrid.
 * @return n/a.
 * @param n/a.
 */
void board::swap() {
    cell** temp = currGrid; // Creating temporary double pointer and initalizing it to currGrid.
    currGrid = secondaryGrid; // Swapping primary to secondary.
    secondaryGrid = temp; // Swapping secondary to

}
/**
 * bool board::isEmpty().
 * @breif - Tests if all cells are dead in 2d array.
 * @return bool.
 * @param n/a.
 */
bool board::isEmpty() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (currGrid[i][j].isAlive()){
                return false;
            }
        }
    }
    return true;
}

/**
 * cell board::cellRules(int neighbors, const cell &c).
 * @breif - applies cell rules to cell.
 * @return cell.
 * @param int neighbors, const cell &c.
 */
cell board::cellRules(int neighbors, const cell &c) {
    cell ret;
    if (neighbors <= 1) { // Dies due to loneliness.
        ret.isAlive(false);
    } else if ((neighbors == 2 || neighbors == 3) && c.isAlive()) { // Stays alive.
        ret.isAlive(true);

    } else if (neighbors == 3 && (!(c.isAlive()))) { // is Born.
        ret.isAlive(true);
    } else { // Dies due to overcrowding.
        ret.isAlive(false);
    }
    return ret;
}

/**
 * int board::getNeighbors(int x, int y).
 * @breif - gets num of neighbors of cell.
 * @return int.
 * @param int x, int y.
 */
int board::getNeighbors(int x, int y) {
    return  (currGrid[x-1][y+1].isAlive())+(currGrid[x-0][y+1].isAlive())+(currGrid[x+1][y+1].isAlive())+
            (currGrid[x-1][y+0].isAlive())+                                   (currGrid[x+1][y+0].isAlive())+
            (currGrid[x-1][y-1].isAlive())+(currGrid[x-0][y-1].isAlive())+(currGrid[x+1][y-1].isAlive());
}


/**
 * cell **board::getCurrGrid() const.
 * @breif - accessor.
 * @return cell**.
 * @param n/a.
 */
cell **board::getCurrGrid() const {
    return currGrid;
}
/**
 * cell **board::setCurrGrid() const.
 * @breif - mutator.
 * @return n/a.
 * @param cell **cg.
 */
void board::setCurrGrid(cell **cg){
    // deletes current board attributes
    for(int i = 0; i < rows; i++){
        delete[] currGrid[i];
        delete[] secondaryGrid[i];
    }
    delete[] currGrid;
    delete[] secondaryGrid;

    // re creates them .
    currGrid = new cell*[rows];
    secondaryGrid = new cell*[rows];

    for(int i = 0; i < rows; i++){
        currGrid[i] = new cell[columns];
        secondaryGrid[i] = new cell[columns];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (cg[i][j].isAlive()){
                currGrid[i][j].isAlive(true);
            } else {
                currGrid[i][j].isAlive(false);
            }
        }
    }

}
/**
 * void board::classicMode().
 * @breif - applies rules of classic mode to currGrid.
 * @return n/a.
 * @param n/a.
 */
void board::classicMode() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0) {
                currGrid[i][j].isAlive(false);
            } else if (i == rows-1) {
                currGrid[i][j].isAlive(false);
            } else if (j == 0) {
                currGrid[i][j].isAlive(false);
            } else if (j == columns-1) {
                currGrid[i][j].isAlive(false);
            } else {
            }
        }
    }
}

/**
 * void board::classicMode().
 * @breif - applies rules of donut mode to currGrid.
 * @return n/a.
 * @param n/a.
 */
void board::donutMode() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            // If margin && not corner ...
            if (i == 0 && (j != 0 && j != columns-1)) {
                currGrid[i][j] = currGrid[i+(rows-2)][j];
            } else if (i == rows-1 && (j != 0 && j != columns-1)) {
                currGrid[i][j] = currGrid[i-(rows-2)][j];
            } else if (j == 0 && (i != 0 && i != rows-1)) {
                currGrid[i][j] = currGrid[i][j+(rows-2)];
            } else if (j == columns-1 && (i != 0 && i != rows-1)) {
                currGrid[i][j] = currGrid[i][j-(rows-2)];
            } else {
                // testing for corners
                if (i == 0 && j == 0){ // Top left (0,0)
                    currGrid[i][j] = currGrid[i+(rows-2)][j+(rows-2)];
                } else if (j == 0 && i == columns-1){ // Top right (0,n-1)
                    currGrid[i][j] = currGrid[i-(rows-2)][j+(rows-2)];
                } else if (i == 0 && j == rows-1){ // bottom left (n-1,0)
                    currGrid[i][j] = currGrid[i+(rows-2)][j-(rows-2)];
                } else if (i == columns-1 && j == rows-1){ // Bottom left (n-1,n-1)
                    currGrid[i][j] = currGrid[i-(rows-2)][j-(rows-2)];
                } else {
                }
            }
        }
    }

}

/**
 * void board::classicMode().
 * @breif - applies rules of mirror mode to currGrid.
 * @return n/a.
 * @param n/a.
 */
void board::mirrorMode() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0 && (j != 0 && j != columns-1)) {
                currGrid[i][j] = currGrid[i+1][j];
            } else if (i == rows-1 && (j != 0 && j != columns-1)) {
                currGrid[i][j] = currGrid[i-1][j];
            } else if (j == 0 && (i != 0 && i != rows-1)) {
                currGrid[i][j] = currGrid[i][j+1];
            } else if (j == columns-1 && (i != 0 && i != rows-1)) {
                currGrid[i][j] = currGrid[i][j-1];
            } else {
                // testing for corners
                if (i == 0 && j == 0){ // Top left (0,0)
                    currGrid[i][j] = currGrid[i+1][j+1];
                } else if (j == 0 && i == columns-1){ // Top right (0,n-1)
                    currGrid[i][j] = currGrid[i-1][j+1];
                } else if (i == 0 && j == rows-1){ // bottom left (n-1,0)
                    currGrid[i][j] = currGrid[i+1][j-1];
                } else if (i == columns-1 && j == rows-1){ // Bottom left (n-1,n-1)
                    currGrid[i][j] = currGrid[i-1][j-1];
                } else {
                }
            }
        }
    }
}

/**
 * void board::setCurrMode(int mode).
 * @breif - mutator.
 * @return n/a.
 * @param int mode.
 */
void board::setCurrMode(int mode) {
    this->mode = mode;
}
/**
 * int board::getCurrMode() const.
 * @breif - accessor.
 * @return int.
 * @param n/a.
 */
int board::getCurrMode() const {
    return mode;
}

/**
 * void board::currMode().
 * @breif - picks curr mode.
 * @return n/a.
 * @param n/a.
 */
void board::currMode() {
    switch (mode) {
    case 0:
        classicMode();
        break;
    case 1:
        donutMode();
        break;
    case 2:
        mirrorMode();
        break;

    default:
        classicMode(); // Defaults to classic mode.
        break;
    }
}

/**
 * void board::nextGeneration().
 * @breif - gets next generation.
 * @return n/a.
 * @param n/a.
 */
void board::nextGeneration() {
    currMode();
    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < columns-1; j++) {
            secondaryGrid[i][j] = cellRules(getNeighbors(i, j), currGrid[i][j]);
        }
    }
    swap();
}

/**
 * bool board::equals(const board& t_b).
 * @breif - tests if boards are equal.
 * @return bool.
 * @param const board& t_b.
 */
bool board::equals(const board& t_b) {
    if (!(this->rows == t_b.rows) && !(this->columns == t_b.columns)) {
        return false;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!(currGrid[i][j].equals(t_b.currGrid[i][j]))) {
                return false;
            }
        }
    }
    return true;
}

/**
 * string board::toString().
 * @breif - converts c** to string.
 * @return string.
 * @param n/a.
 */
string board::toString() {
    string ret = "";
    for (int i = 1; i < rows-1; i++) {
        for (int j = 1; j < columns-1; j++) {
            ret += currGrid[i][j].toChar();
        }
        ret += "\n";
    }
    return ret;
}
