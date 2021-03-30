#ifndef _HELPERFUNCTIONS_H_
#define _HELPERFUNCTIONS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map> //probably unordered_map
#include <vector>
#include "CONST.h"

void readRow(std::stringstream& s, 
             std::vector<std::string>& row) {
  std::string word;

  while(getline(s, word,',')) {
    row.push_back(word);
  }
}

void getAttributes(std::vector<std::pair<std::string, double>>& attributes,
                   std::stringstream& s) {
  std::vector<std::string> row;
  readRow(s, row);

  attributes.push_back( make_pair(row[VAR], std::stod(row[VAL])) );  
}

void addToData(std::map<std::string, std::vector<double>>& data, 
               std::stringstream& s) {
  std::vector<std::string> row;
  readRow(s, row);

  if (data.find(row[VAR]) == data.end() && row[VAR] != "NA") 
    data[row[VAR]] = {std::stod(row[VAL])};
  else if (row[VAL] != "NA")
    data[row[VAR]].push_back(std::stod(row[VAL]));
}

void getVariables(std::map<std::string, std::vector<double>>& data) {
  double mean = 0, max, min, range, changeStoF, numTest;
  for (auto& it : data) {
    numTest = it.second.size();
    changeStoF = *end(it.second) - *begin(it.second);
    max = *begin(it.second), min = *begin(it.second);
    for (auto num : it.second) {
      mean += num;
      if (max < num) 
        max = num;
      else if (num < min)
        min = num;
    }
    mean /= numTest;
    it.second.resize(6);
    it.second = {mean, max, min, range, changeStoF, numTest};
  }
}

void addDataToFiles(std::map<std::string, std::vector<double>>& data,
                    std::vector<std::pair<std::string, double>>& attributes, 
                    int i) {
  std::string filePath;
  std::fstream outFile;
  size_t col_idx = 0, last_idx = 0;

  getVariables(data);

  filePath = "/home/berlands/CODE/STATS503DataChallenge/data/trainData.csv";
  outFile.open(filePath, std::ios::app | std::ios::out);

  for (auto& it : attributes) {
    if (ATT_COLS[col_idx] == it.first) {
      outFile << it.second;
      if (col_idx != 3)
        outFile << ",";
    } else
      std::cout << "Attribute " << ATT_COLS[col_idx] << " missing  on " << i << std::endl;
    col_idx++;
  }

  col_idx = 0;
  for (auto& it : data) {
    while (it.first != COL_NAMES[col_idx]) 
      col_idx++;

    if (col_idx == (COL_NAMES.size() - 1))
      col_idx--;

    if ((col_idx - last_idx) > 0) {
      for (size_t i = 0; i < 6*(col_idx - last_idx); i++)
        outFile << ",";
    } 
    for (size_t i = 0; i < it.second.size(); i++) 
      outFile << "," << it.second[i];

    last_idx = col_idx++;
  }

  outFile << std::endl;
  outFile.close();
}

#endif