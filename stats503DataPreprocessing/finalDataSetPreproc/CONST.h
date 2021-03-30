#ifndef _CONST_H_
#define _CONST_H_

#include <string>
#include <vector>

const std::string mainFilePath = "/home/berlands/x_all/";
const int NUM_OF_OBSERVATIONS = 5000;
const int TIME = 0;
const int VAR = 1;
const int VAL = 2;
const int MISSING = -1;
const std::vector<std::string> COL_NAMES = {"RecordID","Age","Gender","AdmissionType",
                                           "ALP", "ALT", "AST","Albumin","BUN",
                                           "Bilirubin","Cholesterol","Creatinine",
                                           "DiasABP","FiO2","GCS","Glucose","HCO3",
                                           "HCT","HR","K","Lactate","MAP","MechVent",
                                           "Mg","NIDiasABP","NIMAP","NISysABP","Na",
                                           "PaCO2","PaO2","Platelets","RespRate",
                                           "SAPS","SaO2","SysABP","Temp","TroponinI",
                                           "TroponinT","Urine","WBC","noLabel","pH"};
const std::vector<std::string> COL_ADD_ONS = {"mean", "max", "min", "range", 
                                             "changeStoF", "numTest"};

#endif