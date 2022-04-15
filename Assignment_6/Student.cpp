/**
 * @file Student.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for student object
 */
#include "Student.h"
#include <iostream>
using namespace std;

/**
 * Student::Student()
 * @brief create a student object with a entrance time and and wait time
 * @brief default constructor
 * @param n/a
 */
Student::Student(){
  time = 0;
  waitTime = 0;
}

/**
 * Student::Student(int t)
 * @brief overloaded constructor that stores entrance time t
 * @param int t
 */
Student::Student(int t){
  time = t;
  waitTime = 0;
}

/**
 * Student::~Student()
 * @brief default student destructor
 * @param n/a
 */
Student::~Student(){
}

/**
 * void Student::addTime(int t)
 * @brief addtime method that adds to the wait time of a student
 * @param t, wait time to add
 */
void Student::addTime(int t){
  waitTime += t;
}

/**
 * int Student::getTime()
 * @brief getTime method that returns the entrance time
 * @param n/a
 * @return int
 */
int Student::getTime(){
  return time;
}

/**
 * int Student::getWaitTime()
 * @brief getWaitTime method returns the wait time of the student
 * @param n/a
 * @return int
 */
int Student::getWaitTime(){
  return waitTime;
}
