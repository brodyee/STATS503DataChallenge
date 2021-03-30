
// Brody Erlandson - March 5, 2021
// This takes the individual .csv files from the data and makes
// a singular .csv file. It reads in each file, engineers the
// variables needed, and adds it to a map. Finally, outputs the 
// map as a .csv

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map> //probably unordered_map
#include <vector>
#include "CONST.h"
#include "helperFunctions.h"
using namespace std;

int main(int argc,
         char *argv[]) {
  map<string, vector<double>> data;
  vector<int> idxs;
  vector<pair<string, double>> attributes;
  fstream inFile;
  string filePath, line;
  int age, gender, admitType;
  double currVarVal;

  // gets the train indices
  idxs.reserve(7090);
  for (size_t i = 1; i < 2/*7090*/; i++)
    idxs.push_back(i);

  // gets the column names printed
  fstream outFile;
  filePath = "/home/berlands/CODE/STATS503DataChallenge/data/trainData.csv";
  outFile.open(filePath, std::ios::app | std::ios::out); 

  for (auto col : COL_NAMES)
    outFile << col << ","; 

  outFile << std::endl;
  outFile.close();

  // puts data in the file
  for (auto idx : idxs) {
    filePath = mainFilePath + to_string(idx) + ".txt";
    inFile.open(filePath.c_str(), ios::in);
    if (inFile.fail())
      return 1;

    getline(inFile, line); // gets Time,Variable,Value out of the way
    for (int i = 0; i < 4; i++) {
      getline(inFile, line);
      stringstream s(line);
      getAttributes(attributes, s);
    }

    while (getline(inFile, line)) {  
      stringstream s(line);
             
      addToData(data, s);
    }
           
    addDataToFiles(data, attributes, idx);
    data.clear();
    inFile.close();
  }

  return 0;
}
