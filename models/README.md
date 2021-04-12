### Model Fittings:

+ Random Forest and Boosting: fit these two models on the final imputed training set, then use the final imputed test set to calculate the test error and AUC. After tuning the parameters, select the ones that has highest test accuracy and AUC values. Code for this part is `Model Fitting2.Rmd`.

+ Support Vector Machines: use radial and polynomial kernal to fit the final inputed trainig set, use the same process described above to find the best svm model. Code for this part is `Model_Fitting_SVM.Rmd`.
