#ifndef _HELPERFUNCTIONS_H_
#define _HELPERFUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map> //probably unordered_map
#include <vector>
#include "CONST.h"

void readRow(std::stringstream& s, 
             std::vector<std::string>& row) {
  std::string word;

  while(getline(s, word,',')) {
    row.push_back(word);
  }
}

void getIdxs(std::fstream& stream, 
             std::vector<int>& idxs) {
  std::string line;

  idxs.reserve(NUM_OF_OBSERVATIONS);
  while(getline(stream, line)) {
    idxs.push_back(stoi(line));
  }
}

void getAttributes(std::fstream& stream, 
                   std::vector<double>& patientAtt) {
  std::string line;
  std::vector<std::string> row;

  getline(stream, line); //gets junk first line
  for (int i = 0; i < 4; i++) {
    getline(stream, line);
    std::stringstream s(line);
    readRow(s, row);
    patientAtt.push_back(std::stod(row[VAL]));
    row.clear();
  }
}

void addToData(std::unordered_map<std::string, std::vector<double>>& data, 
               std::stringstream& s, 
               const std::vector<double> patientAtt) {
  std::vector<std::string> row;
  readRow(s, row);

  if (data.find(row[VAR]) == data.end()) 
    data[row[VAR]] = patientAtt;
  if (row[VAL] != "NA")
    data[row[VAR]].push_back(std::stod(row[VAL]));
  else
    data[row[VAR]].push_back(-1);
}

void addDataToFiles(std::unordered_map<std::string, std::vector<double>>& data,
                    int i) {
  std::string filePath;
  std::fstream outFile;

  for (auto it : data) {
    filePath = "/home/berlands/CODE/STATS503DataChallenge/data/eachVar/" + it.first + ".csv";
    outFile.open(filePath, std::ios::app | std::ios::out);

    outFile << it.second[0];
    for (size_t i = 1; i < it.second.size(); i++) 
      outFile << "," << it.second[i];
    outFile << std::endl;
    outFile.close();
  }
}

#endif