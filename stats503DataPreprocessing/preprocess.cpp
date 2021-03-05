
// Brody Erlandson - March 5, 2021
// This takes the individual .csv files from the data and makes
// a singular .csv file. It reads in each file, engineers the
// variables needed, and adds it to a map. Finally, outputs the 
// map as a .csv

#include <fstream>
#include <map>
#include "CONST.h"
#include "helperFunctions.h"
using namespace std;

int main(int argc,
         char *argv[]) {
  map<string, double[NUM_OF_OBSERVATIONS]> data;
  fstream inFile;
  string filePath;

  return 0;
}