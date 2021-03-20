# Each Variable .csv for EDA and engineering variables.

### Data Setup
Each .csv is ready to be read into either R or Python directly, here are a few quick notes:
* There are no column labels
* The first 4 columns are: RecordID, Age, Gender, and AdmissionType
* You can get whether the patient recovered or not in the file `train_outcome.csv` in the data folder (use the RecordID to locate the outcome). 


Further detail: \
Each csv file contains many N/A's, for not every patient got the same amount of test. However, all N/A's will be after all of the patients test scores. Also, the tests are in order of time received. This means if a test was taken at 00:00:00 and at 00:30:00, then the one at 00:00:00 will be listed first. Though the actual time of the test is not given. This is because there are tests taken at the same time. It is assumed that the one listed first came first, but their time listing is the same.  

### Plan for EDA
EDA's will probably be very repetitive. We just want to see what kind of engineered variable(s) will do nicely for summarizing that particular variable. For example, if we have variable X, then we'd have a file called `X.csv`. This `X.csv` would only contain the patients that had this variable in their data. So if a patient never had the X test taken, then that patient will *not* be in `X.csv`. From this `X.csv` we can test whether change-over-time matters, or if a general statistic like mean will be sufficient. Once we find at least one (could be more than one) statistic that separates recovered vs. not recovered well, we can use this/these statistic(s) in our final data set. Though there are a lot of variables, we will most likely be running the same tests on every variable. So after the first few it will go pretty quickly. 
