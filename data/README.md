# Data Sets stored here

`trainData.csv` is all the patient data files up to (not including) 7090. I did max, min, mean, range, changeStoF, and numTest for every thing other than the first 4 attributes. Though it is named trainData, it should be split (70/30 or 80/20) for a test set before you do anything. The 7090 on files are for the turn in, so we don't know the results. There are a lot of N/A's, given not every test for every person.


`Training set for trainData.csv` is the training dataset for trainData, it has 4962 observations, which is 70% of the trainData. There is no NA value as the data imputation is applied. I first splited the training set into two groups by outcome, then for each group filter by AdmissionType and numTest = 1, and calculate the mean of the test_mean, which is used to replace the NA values. Some of the tests do not have observations that numTest = 1, then use the range <= median of test_range as limitation to filter the data. For example, the RespRate does not have observation such that numTest = 1 for some AdmissionType, so instead of being filtered by AdmissionType and numTest =1 it is filtered by AdmissionType and range <= 13, as the median value of RespRate_range is around 13. 

`Test set for trainData.csv` is the test set for trainData, it has 2127 observations, which is 30% of the trainData. Using the same way described above to perform data imputation. 
