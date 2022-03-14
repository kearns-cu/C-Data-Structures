/**
 * @file game.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief game class with modes, cells, and boardx
 */

#ifndef GAME_H
#define GAME_H

#include "cell.h"
#include "board.h"
#include <string>

class game {
private:
    board currGen, nextGen;
    int genCount = 0;

public:
    game();
    virtual ~game();

    void InitBoard(cell** i_c, int rows, int columns, int bound, double percent);

    bool isStable();

    void setMode(int mode);

    board getCurrGen() const;
    board getNextGen() const;

    void playOffEntr();
    void playOffTime(int millsec);
    string toString();
};


#endif
