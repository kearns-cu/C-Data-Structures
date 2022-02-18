/*
Parser.cpp
Takes a user input in the form of a string and outputs summary of string to an output.txt file
*/

#include <iostream>
#include <string>
#include "Parser.h"
#include <fstream>
using namespace std;

/*
Parser
Parser's default constructor
Sets instance variables defaults
*/
Parser::Parser(){
  inputString = "";
  outputSummary = "";
}

/*
Parser
Parser's overloaded constructor
@param string input
*/
Parser::Parser(string input){
  inputString = input + " ";
  outputSummary = count(inputString);
}

/*
Parser
Parser's destructor
*/
Parser::~Parser(){
}
/*
Parser
Count function which counts the letters, alphabets, non-alphabets, and pairs in the string
@param string input
@return string summary of the user string
*/
string Parser::count(string str){
  string countOutput;
  int upper = 0, lower = 0, number = 0, special = 0, space = 0, alphabets = 0, pairs = 0;
  double average = 0.0;
    for (int i = 0; i < str.length(); i++){
      if(str[i] >= 'A' && str[i] <= 'Z')
          upper++;
      else if(str[i] >= 'a' && str[i] <= 'z')
          lower++;
      else if(str[i]>= '0' && str[i]<= '9')
          number++;
      else
          special++;
    }

    for(int i = 0; i < str.length(); ++i){
        if(str[i] == str[i + 1]){
          pairs++;
      }
    }

    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0, t = 0, u = 0, v = 0, x = 0, w = 0, y = 0, z = 0;
      for (int i = 0; i < str.length(); i++){
        if(str[i] == 'a' || str[i] == 'A')
            a++;
        else if(str[i] == 'b' || str[i] == 'B')
            b++;
        else if(str[i] == 'c' || str[i] == 'C')
            c++;
        else if(str[i] == 'd' || str[i] == 'D')
            d++;
        else if(str[i] == 'e' || str[i] == 'E')
            e++;
        else if(str[i] == 'f' || str[i] == 'F')
            f++;
        else if(str[i] == 'g' || str[i] == 'G')
            g++;
        else if(str[i] == 'h' || str[i] == 'H')
           h++;
       else if(str[i] == 'i' || str[i] == 'I')
           i++;
       else if(str[i] == 'j' || str[i] == 'J')
           j++;
       else if(str[i] == 'k' || str[i] == 'K')
           k++;
       else if(str[i] == 'l' || str[i] == 'L')
           l++;
       else if(str[i] == 'm' || str[i] == 'M')
           m++;
       else if(str[i] == 'n' || str[i] == 'N')
           n++;
      else if(str[i] == 'o' || str[i] == 'O')
           o++;
      else if(str[i] == 'p' || str[i] == 'P')
           p++;
      else if(str[i] == 'q' || str[i] == 'Q')
           q++;
      else if(str[i] == 'r' || str[i] == 'R')
           r++;
      else if(str[i] == 's' || str[i] == 'S')
            s++;
      else if(str[i] == 't' || str[i] == 'T')
            t++;
      else if(str[i] == 'u' || str[i] == 'U')
            u++;
      else if(str[i] == 'v' || str[i] == 'V')
            v++;
      else if(str[i] == 'w' || str[i] == 'W')
            w++;
      else if(str[i] == 'x' || str[i] == 'X')
            x++;
      else if(str[i] == 'y' || str[i] == 'Y')
            y++;
      else if(str[i] == 'z' || str[i] == 'Z')
            z++;
      else if(str[i] == ' ')
          space++;
      }
      alphabets = upper + lower;
      special -= space;
      average = (a+b+c+d+e+f+g+h+i+j+k+l+m+n+o+p+q+r+s+t+u+v+w+x+y+z) / 26.0;
    countOutput += std::string("Your string: ") + str;
    countOutput += "\n " + std::string("a: ") + std::to_string(a);
    countOutput += "\n " + std::string("b: ") + std::to_string(b);
    countOutput += "\n " + std::string("c: ") + std::to_string(c);
    countOutput += "\n " + std::string("d: ") + std::to_string(d);
    countOutput += "\n " + std::string("e: ") + std::to_string(e);
    countOutput += "\n " + std::string("f: ") + std::to_string(f);
    countOutput += "\n " + std::string("g: ") + std::to_string(g);
    countOutput += "\n " + std::string("h: ") + std::to_string(h);
    countOutput += "\n " + std::string("i: ") + std::to_string(i);
    countOutput += "\n " + std::string("j: ") + std::to_string(j);
    countOutput += "\n " + std::string("k: ") + std::to_string(k);
    countOutput += "\n " + std::string("l: ") + std::to_string(l);
    countOutput += "\n " + std::string("m: ") + std::to_string(m);
    countOutput += "\n " + std::string("n: ") + std::to_string(n);
    countOutput += "\n " + std::string("o: ") + std::to_string(o);
    countOutput += "\n " + std::string("p: ") + std::to_string(p);
    countOutput += "\n " + std::string("q: ") + std::to_string(q);
    countOutput += "\n " + std::string("r: ") + std::to_string(r);
    countOutput += "\n " + std::string("s: ") + std::to_string(s);
    countOutput += "\n " + std::string("t: ") + std::to_string(t);
    countOutput += "\n " + std::string("u: ") + std::to_string(u);
    countOutput += "\n " + std::string("v: ") + std::to_string(v);
    countOutput += "\n " + std::string("w: ") + std::to_string(w);
    countOutput += "\n " + std::string("x: ") + std::to_string(x);
    countOutput += "\n " + std::string("y: ") + std::to_string(y);
    countOutput += "\n " + std::string("z: ") + std::to_string(z);
    countOutput += "\n " + std::string("Alphabets: ") + std::to_string(alphabets);
    countOutput += "\n " + std::string("Non-Alphabets: ") + std::to_string(special);
    countOutput += "\n " + std::string("Average Occurance: ") + std::to_string(average);
    countOutput += "\n " + std::string("Pairs: ") + std::to_string(pairs);
    return countOutput;
 }

 /*
printToFile
 Print the instance's summaryOutput to a file
 @param filename
 */
void Parser::printToFile(string fileName){
  ofstream MyFile(fileName);
  cout << "File Created" << endl;
  MyFile << outputSummary << endl;
  cout << "Wrote to File" << endl;
  MyFile.close();

}

string Parser::getSummary(){
  return outputSummary;
}
