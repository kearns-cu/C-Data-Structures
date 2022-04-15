/**
 * @file Window.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for window object
 */
#include "Window.h"
#include <iostream>
using namespace std;

/**
 * Window::Window()
 * @brief create a window object with a time and occupiedTime variable
 * @brief default constructor
 * @param n/a
 */
Window::Window(){
  time = 0;
  occupiedTime = 0;
}

/**
 * Window::Window(int t)
 * @brief create a window object and initializes member variables
 * @brief overloaded constructor
 * @param int t
 */
Window::Window(int t){
  time = t;
  occupied = false;
  currently = false;
}

/**
 * Window::~Window()
 * @brief destructs a window object
 * @brief default destructor
 * @param int t
 */
Window::~Window(){
}

/**
 * void Window::addWaitTime(int t)
 * @brief adds to the wait time member variable
 * @param int t
 * @return void
 */
void Window::addWaitTime(int t){
  time = t;
}

/**
 * int Window::getWaitTime()
 * @brief returns the wait time
 * @param n/a
 * @return int
 */
int Window::getWaitTime(){
  return time;
}

/**
 * bool Window::isOccupied()
 * @brief returns whether window is occupied
 * @param n/a
 * @return bool
 */
bool Window::isOccupied(){
  return occupied;
}

/**
 * void Window::updateTrue()
 * @brief changes occupied status to true
 * @param n/a
 * @return void
 */
void Window::updateTrue(){
  occupied = true;
}

/**
 * void Window::updateFalse()
 * @brief changes occupied status to false
 * @param n/a
 * @return void
 */
void Window::updateFalse(){
  occupied = false;
}

/**
 * void Window::addOccupiedTime()
 * @brief adds time to occupied time member variable
 * @param int t
 * @return void
 */
void Window::addOccupiedTime(int t){
  occupiedTime += t;
}

/**
 * void Window::getOccupiedTime()
 * @brief returns the occupied time of a window
 * @param n/a
 * @return int
 */
int Window::getOccupiedTime(){
  return occupiedTime;
}

/**
 * void Window::isCurrentlyOccupied()
 * @brief sets currently to true when occupied
 * @param n/a
 * @return void
 */
void Window::isCurrentlyOccupied(){
  currently = true;
}
/**
 * void Window::notCurrentlyOccupied()
 * @brief sets currently to false when not occupied
 * @param n/a
 * @return void
 */
void Window::notCurrentlyOccupied(){
  currently = false;
}

/**
 * void Window::getCurrentlyOccupied()
 * @brief returns currently occupied status
 * @param n/a
 * @return bool
 */
bool Window::getCurrentlyOccupied(){
  return currently;
}
