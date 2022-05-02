/**
 * @file User.cpp
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief cpp file for User object
 */
#include <iostream>
#include "User.h"

using namespace std;

/**
 * User::User()
 * @brief creates a User object
 * @brief default constructor
 * @param n/a
 */
User::User(){
  id = 0;
  name = "";
  level = "";
}

/**
 * User::User(int inputID, string inputName, string inputLevel)
 * @brief creates a User object
 * @brief overloaded constructor
 * @param n/a
 */
User::User(int inputID, string inputName, string inputLevel)
{
  id = inputID;
  name = inputName;
  level = inputLevel;
}

/**
 * User::~User()
 * @brief destructs a User object
 * @brief default destructor
 * @param n/a
 */
User::~User(){
}

/**
 * void User::setID(int id)
 * @brief set the id of the user object
 * @param int id number
 * @return void
 */
void User::setID(int id){
  id = id;
}

/**
 * void User::setName(string setName)
 * @brief set the name of the user object
 * @param string name
 * @return void
 */
void User::setName(string setName){
  name = setName;
}

/**
 * void User::setLevel(string setLevel)
 * @brief set the level of the user object
 * @param string level
 * @return void
 */
void User::setLevel(string setLevel){
  level = setLevel;
}

/**
 * int User::getID()
 * @brief returns the ID of the user object
 * @param n/a
 * @return int
 */
int User::getID(){
  return id;
}

/**
 * string User::getName()
 * @brief returns the name of the user object
 * @param n/a
 * @return string
 */
string User::getName(){
  return name;
}

/**
 * string User::getLevel()
 * @brief returns the level of the user object
 * @param n/a
 * @return string
 */
string User::getLevel(){
  return level;
}
