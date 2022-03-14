/**
 * @file game.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief Game class to create board and apply modes
 */

#include "game.h"
#include "cell.h"
#include "board.h"
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


// Default Constructor
game::game() {

}


// Destructor
game::~game() {
    // Empty - no dynamically allocated memoery.
}

/**
 * void game::InitBoard(cell** i_c, int rows, int columns, int bound, double percent).
 * @breif - Passes initial board.
 * @return n/a.
 * @param cell** i_c, int rows, int columns, int bound, double percent.
 */
void game::InitBoard(cell** i_c, int rows, int columns, int bound, double percent){
    currGen.Initialize(i_c, rows, columns, bound, percent);
    nextGen.Initialize(i_c, rows, columns, bound, percent);
}
/**
 * bool game::isStable().
 * @breif - Tests if game is stable.
 * @return bool.
 * @param n/a.
 */
bool game::isStable(){
    if (currGen.equals(nextGen)) {
        return true;
    }
    return false;
}


/**
 * board game::getCurrGen() const.
 * @breif - Accessor.
 * @return board currGen.
 * @param n/a.
 */
board game::getCurrGen() const{
    return currGen;
}
/**
 * board game::getNextGen() const.
 * @breif - Accessor.
 * @return board NextGen.
 * @param n/a.
 */
board game::getNextGen() const{
    return nextGen;
}

/**
 * void game::setMode(int mode).
 * @breif - Mutator for mode.
 * @return n/a.
 * @param int mode.
 */
void game::setMode(int mode){
    currGen.setCurrMode(mode);
    nextGen.setCurrMode(mode);
}



/**
 * void game::playOffEntr().
 * @breif - Executes for output [0].
 * @return n/a.
 * @param n/a.
 */
void game::playOffEntr() {
    switch (currGen.getCurrMode()){
    case 0:
        cout << "Classic" << endl;
        break;
    case 1:
        cout << "Donut" << endl;
        break;
    case 2:
        cout << "Mirror" << endl;
        break;
    }
    genCount = 0;
    nextGen.nextGeneration();
    // FIX isEmpty().
    cout << endl << "Gen 0 (input)" << endl;
    cout << currGen.toString() << endl;
    currGen.nextGeneration();
    nextGen.nextGeneration();
    genCount+=1;
    cout << "Press [enter] to continue ... ";
    cin.ignore();
    cin.ignore();
    bool terminate = false;
    int stopVal = 100;
    while ((currGen.isEmpty()) || !(isStable()) && genCount <= stopVal) {
        cout << endl;
        cout << "Gen " << genCount << endl;
        cout << currGen.toString() << endl;
        currGen.nextGeneration();
        nextGen.nextGeneration();
        genCount+=1;
        if (currGen.isEmpty()){
            cout << "All cells are dead" << endl << endl;
            break;
        } else if (isStable()){
            cout << "Stability Achieved" << endl << endl;
            break;
        } else if (genCount == stopVal+1){
            cout << "It's been " << stopVal << " generations. I'm putting an end to this!" << endl << endl;
            break;
        } else {
            cout << "Press [enter] to continue ... ";
            cin.ignore();
            cout << endl;
        }
    }


}

/**
 * void game::playOffTime().
 * @breif - Executes for output [2].
 * @return n/a.
 * @param int millsec.
 */
void game::playOffTime(int millsec) {
    switch (currGen.getCurrMode()){
    case 0:
        cout << "Classic" << endl;
        break;
    case 1:
        cout << "Donut" << endl;
        break;
    case 2:
        cout << "Mirror" << endl;
        break;
    }
    genCount = 0;
    nextGen.nextGeneration();
    cout << endl << "Gen 0 (input)" << endl;
    cout << currGen.toString() << endl;
    currGen.nextGeneration();
    nextGen.nextGeneration();
    genCount+=1;
    bool terminate = false;
    int stopVal = 100;

        while ((currGen.isEmpty()) || !(isStable()) && genCount <= stopVal) {
        std::this_thread::sleep_for(std::chrono::milliseconds(millsec));
            cout << endl;
            cout << "Gen " << genCount << endl;
            cout << currGen.toString() << endl;
            currGen.nextGeneration();
            nextGen.nextGeneration();
            genCount+=1;
            if (currGen.isEmpty()){
                cout << "All cells are dead" << endl << endl;
                break;
            } else if (isStable()){
                cout << "Stability Achieved" << endl << endl;
                break;
            } else if (genCount == stopVal+1){
                cout << "It's been " << stopVal << " generations. I'm putting an end to this!" << endl << endl;
                break;
            } else {
                cout << endl;
            }
        }



}

/**
 * string game::toString().
 * @breif - toString of game.
 * @return string.
 * @param n/a.
 */
string game::toString() {
    string ret = "";
    switch (currGen.getCurrMode()){
    case 0:
        ret += "Classic\n";
        break;
    case 1:
        ret += "Donut\n";
        break;
    case 2:
        ret += "Mirror\n";
        break;
    }
    genCount = 0;
    nextGen.nextGeneration();
    ret += "\nGen 0 (input)\n";
    ret += currGen.toString() + "\n";
    currGen.nextGeneration();
    nextGen.nextGeneration();
    genCount+=1;
    int stopVal = 100;
    while ((currGen.isEmpty()) || !(isStable()) && genCount <= stopVal) {
        ret += "Gen " + to_string(genCount) + "\n";
        ret += currGen.toString();
        currGen.nextGeneration();
        nextGen.nextGeneration();
        genCount+=1;
        if (isStable()){
            ret += "\nStability Achieved";
        } else if (currGen.isEmpty()){
            ret += "\nAll cells are dead";
        } else if (genCount == stopVal+1){
            cout << "It's been " << stopVal << " generations. I'm putting an end to this!" << endl << endl;
            break;
        } else {
            ret += "\n";
        }
    }




return ret;
}
