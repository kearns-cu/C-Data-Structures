/**
 * @file User.h
 * @author rkearns@chapman.edu
 * ID: 2366311
 * @brief header file for a user object
 */
#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;

class User{
public:
  User();
  User(int setid, string setname, string setlevel);
  ~User();
  void setID(int setID);
  void setName(string setName);
  void setLevel(string setLevel);
  int getID();
  string getName();
  string getLevel();

protected:
  int id;
  string name;
  string level;
};

#endif
