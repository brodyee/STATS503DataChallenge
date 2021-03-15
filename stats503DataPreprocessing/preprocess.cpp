
// Brody Erlandson - March 5, 2021
// This takes the individual .csv files from the data and makes
// a singular .csv file. It reads in each file, engineers the
// variables needed, and adds it to a map. Finally, outputs the 
// map as a .csv

#include <fstream>
#inlcude <string>
#include <stringstream>
#include <map> //probably unordered_map
#include "CONST.h"
#include "helperFunctions.h"
using namespace std;

int main(int argc,
         char *argv[]) {
  map<string, container> data;
  vector<string> row;
  fstream inFile;
  string filePath, line;
  int age, gender, admitType;
  double currVarVal;

  for (int i = 1; i <= NUM_OF_OBSERVATIONS; i++) {
    filePath = mainFilePath + to_string(i) + ".csv";
    inFile.open(filePath, ios::in);
           
    while (inFile >> line) {
      row.clear();
             
      getline(inFile, line);
      stringstream s(line);
      
      row = readRow(s);
             
      addToData(data, row);
    }
           
    addDataToFiles(data, i);
    data.clear();
  }

  return 0;
}
