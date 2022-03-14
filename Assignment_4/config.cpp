/**
 * @file config.cpp.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief get/set/executes settings.
 */

#include "config.h"
#include "game.h"
#include "fileProcessor.h"
#include <iostream>


using namespace std;

// Default Constructor.
config::config() {

}

// Destructor.
config::~config() {
    // Empty - no dynamically allocated memoery.
}

/**
 * void config::setSettings().
 * @breif - gets/sets settings from user.
 * @return n/a.
 * @param n/a.
 */
void config::setSettings(){
    int input;
    bool success = false;
    while (success == false) {
        cout << "[0]Random Configuration, or [1]Flat-file: ";
        cin >> input;
        if (input >= 0 && input <= 1) {
            this->bound = input;
            success = true;
            if (input == 1) {
                cout << "Input file name: ";
                cin >> inputFile;
            } else if (input == 0) {
                cout << "Rows (height): ";
                cin >> rows;
                cout << "Columns (width): ";
                cin >> columns;
                cout << "Percent of cells alive: ";
                cin >> percentA;

            }



        } else {
            cout << "Please try again." << endl;
        }
    }
    success = false;
    while (success == false) {
        cout << "[0]Classic mode, [1]Donut mode, or [2]Mirror mode: ";
        cin >> input;
        if (input >= 0 && input <= 2) {
            this->mode = input;
            currGame.setMode(input);
            success = true;
        } else {
            cout << "Please try again." << endl;
        }
    }
    success = false;
    while (success == false) {
        cout << "[0]Enter for next Generation, [1]File output, or [2]Next gen every (x) milliseconds: ";
        cin >> input;
        if (input >= 0 && input <= 2) {
            this->output = input;
            success = true;
            if (input == 1) {
                cout << "Output file name: ";
                cin >> outputFile;
            } else if (input == 2) {
                cout << "How many milliseconds inbetween generations (1000 = 1 second): ";
                cin >> usr_tme;
            }

        } else {
            cout << "Please try again." << endl;
        }
    }


}

/**
 * void config::Execute().
 * @breif - Executes game with users settings.
 * @return n/a.
 * @param n/a.
 */
void config::Execute() {
    if (bound == 0) {
        // works
        currGame.InitBoard(nullptr, rows+2, columns+2, bound, percentA);
    } else if (bound == 1) {
        currGame.InitBoard(processor.processInputFile(inputFile), processor.getRows(), processor.getColumns(), bound, 1);
    }
    switch (output) {
    case 0:
        currGame.playOffEntr();
        break;
    case 1:
        processor.processOutputFile(outputFile, currGame.toString());
        break;
    case 2:
        currGame.playOffTime(usr_tme);
        break;

    default:
        break;

    }
}
