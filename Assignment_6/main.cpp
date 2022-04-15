#include "registrar.h"
#include <iostream>

using namespace std;

int main (int argc, char **argv){

  if(argc == 1){
    cout << "Enter the file name: " << endl;
    return 0;
  }

  string file = argv[1];
  Registrar* lobby = new Registrar();
  lobby->simulation(file);

}
