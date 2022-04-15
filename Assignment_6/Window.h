/**
 * @file Window.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header file for window object
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
using namespace std;

/**
 * class Window
 * @brief class for window object
 * @return n/a
 * @param n/a
 */
class Window{
  public:
    Window();
    Window(int i);
    ~Window();
    bool isOccupied();
    void addOccupiedTime(int t);
    void updateTrue();
    void updateFalse();
    int getOccupiedTime();
    void addWaitTime(int t);
    int getWaitTime();
    void isCurrentlyOccupied();
    void notCurrentlyOccupied();
    bool getCurrentlyOccupied();

  private:
    int time;
    bool occupied;
    int occupiedTime;
    bool currently;

};
#endif
