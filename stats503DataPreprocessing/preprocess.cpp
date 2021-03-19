
// Brody Erlandson - March 5, 2021
// This takes the individual .csv files from the data and makes
// a singular .csv file. It reads in each file, engineers the
// variables needed, and adds it to a map. Finally, outputs the 
// map as a .csv

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map> //probably unordered_map
#include <vector>
#include "CONST.h"
#include "helperFunctions.h"
using namespace std;

int main(int argc,
         char *argv[]) {
  unordered_map<string, vector<double>> data;
  vector<int> idxs;
  vector<double> patientAtt;
  fstream inFile;
  string filePath, line;
  int age, gender, admitType;
  double currVarVal;

  filePath = "/home/berlands/CODE/STATS503DataChallenge/data/trainInd.txt";
  inFile.open(filePath.c_str(), ios::in);
  if (inFile.fail())
    return 1;
  getIdxs(inFile, idxs);
  inFile.close();

  for (auto idx : idxs) {
    filePath = mainFilePath + to_string(idx) + ".txt";
    inFile.open(filePath.c_str(), ios::in);
    if (inFile.fail())
      return 1;

    getAttributes(inFile, patientAtt);
           
    while (getline(inFile, line)) {  
      stringstream s(line);
             
      addToData(data, s, patientAtt);
    }
           
    addDataToFiles(data, idx);
    data.clear();
    patientAtt.clear();
    inFile.close();
  }

  return 0;
}
