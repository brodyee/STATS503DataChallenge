# Data Sets stored here

`trainData.csv` is all the patient data files up to (not including) 7090. I did max, min, mean, range, changeStoF, and numTest for every thing other than the first 4 attributes. Though it is named trainData, it should be split (70/30 or 80/20) for a test set before you do anything. The 7090 on files are for the turn in, so we don't know the results. There are a lot of N/A's, given not every test for every person.


`Training set(Outcome=0).csv`  and `Test set(Outcome=0).csv` are the imputed datasets. The train.id used the id given in `trainInd.txt`. Only use the recovered observation to calculate the mean of each test_mean based on the AdmissionType, then replaced the NA values by the calculated mean based on AdmissionType.

`Training set.csv` and `Test set.csv`: only use AdmissionType and numTest = 1 to filter the data, then calculate the mean of the test_mean after filtering. Replace the NA values with the calculated mean based on the AdmissionType. For the tests that do not have enough observations satisfy numTest=1, using test_range <= median(test_range) instead. 

`testData_onlyOutcome0.csv` and `trainData_onlyOutcome0.csv` are the imputed datasets. he train.id used the id given in `trainInd.txt`. Only use the recovered observation to calculate the mean for missing data regardless of other variables (Admission Type is **not** used for grouping). I assume this is the simpliest data imputation process.
