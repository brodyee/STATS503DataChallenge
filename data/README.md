# Data Sets stored here

`trainData.csv` is all the patient data files up to (not including) 7090. I did max, min, mean, range, changeStoF, and numTest for every thing other than the first 4 attributes. Though it is named trainData, it will be split (70/30) for a training set and a test set before data imputation. Data imputation is needed, as there are a lot of N/A's, given not every test for every person. 

`trainInd.txt` is the RecordID for the training set, so that we could ensure that we use the same training set and test set when we apply different ways of data imputation and models. 

`train_outcome.csv` stored the outcome for the first 7089 patients, which are the patients in `trainData.csv`.

`testData.csv` is all the patient data files excpet the first 7089 files. Same as the `trainData.csv`, includes max, min, mean, range, changeStoF, and numTest for every thing other than the first 4 attributes. For the missing value, use the same method of data imputation that applies on `trainData.csv` to perform data imputation on this test data.

`BrodysImpute_Age_Outcome_Gender-testSet.csv` and `BrodysImpute_Age_Outcome_Gender-trainSet.csv` are the final imputed training/test set we used to fit the models. We first compute the mean in training set based on age and gender, then replace the NA values in either training set or test set by the mean computed before based on the age and gender of the patient that has this NA value.

### Other three ways we used to do mean imputation:

+ Mean inputation based on outcome, number of tests, and AdmissionType: only use the recovered and numTest=1 observations to calculate the mean of each test_mean based on the AdmissionType, then replaced the NA values by the calculated mean based on AdmissionType. `Data imputation2.Rmd` is the code for doing this data imputation.

+ Mean inputation based on AdmissionType and number of tests: only use AdmissionType and numTest = 1 to filter the data, then calculate the mean of the test_mean after filtering. Replace the NA values with the calculated mean based on the AdmissionType. For the tests that do not have enough observations satisfy numTest=1, using test_range <= median(test_range) instead. `Data imputation.Rmd` is the code for doing this data imputation.

+ Mean inputation only based on the outcome: only use the recovered observation to calculate the mean for missing data regardless of other variables (Admission Type is **not** used for grouping), assuming this is the simpliest data imputation process. `data_imputation_byOutcome_Ji.Rmd` is the code for doing this data imputation.


### Model Fittings:

+ Random Forest and Boosting: fit these two models on the final imputed training set, then use the final imputed test set to calculate the test error and AUC. After tuning the parameters, select the ones that has highest test accuracy and AUC values. Code for this part is `Model Fitting2.Rmd`.

+ Support Vector Machines: use radial and polynomial kernal to fit the final inputed trainig set, use the same process described above to find the best svm model. Code for this part is `Model_Fitting_SVM.Rmd`.
