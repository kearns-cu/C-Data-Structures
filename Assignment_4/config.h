/**
 * @file config.h.
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief get/set/executes settings.
 */

#ifndef CONFIG_H
#define CONFIG_H

#include "game.h"
#include "fileProcessor.h"

#include <string>
#include <iostream>

class config {
private:
    int bound, mode, output, rows, columns, usr_tme;
    double percentA;
    string inputFile, outputFile;
    game currGame;
    fileProcessor processor;

public:
    config();
    virtual ~config();

    void setSettings();
    void Execute();


};

#endif
