
#include <map>
#include <string>
#include "CONST.h"

vector<string> readRow(stringstream& s);

void addToData(std::map<string, container>& data, vector<string>& row);

void addDataToFiles(std::map<string, container>& data, int i);

