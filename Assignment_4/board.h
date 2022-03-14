/**
 * @file board.h.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief board for game of life.
 */

#ifndef BOARD_H
#define BOARD_H


#include "cell.h"
#include <string>

using namespace std;

class board {
private:
    cell **currGrid, **secondaryGrid;
    int rows, columns, mode;
public:
    board(); // Initalizes gen 0.
    virtual ~board(); // I NEED THIS

    void Initialize(cell** i_c, int rows, int columns, int bound, double percent);

    void swap();
    bool isEmpty();

    cell cellRules(int neighbors, const cell &c);
    int getNeighbors(int x, int y);

    void classicMode();
    void donutMode();
    void mirrorMode();

    void setCurrMode(int mode);
    int getCurrMode() const;
    void currMode();

    void setRows(int rows);
    void setColumns(int columns);

    void nextGeneration();



    cell **getCurrGrid() const;
    void setCurrGrid(cell **currGrid);

    bool equals(const board& t_b);
    // bool equals(board& t_b);
    string toString();


};

#endif
