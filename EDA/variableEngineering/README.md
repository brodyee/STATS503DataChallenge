# EDA on each `var.csv`

* Brody's EDA: I didn't find many particular statistics/engineered variables that split the outcome well. After a little thought, this is not surprising. Because one variable is probably not going to split it well. So, it is probably best to come up with a few statistics/engineered variables that we think would magnify something that may be important. Here are the variables that I came up with:
  * Mean, Max, Min, and Range: Not much explanation needed
  * ChangeStoF: Simular to range, but (instead of max - min) it is last test minus first test. This is to try to capture the change over time. If it is a linear change over time, then range ~= ChangeStoF. However, if it is a non-linear change, then range != ChangeStoF.
  * numTest: This may or may not be helpful. It seems that for some test, being tested a lot may be a sign that one is/is not recovering. It will be interesting to see if this helps. 


* Entong's EDA: For some test, the minimum value and mean value seem to have some relation with the outcome, but most of time none of these statistics/engineered variables could tell any difference between two groups of outcome. The only one thing I find, though may be not useful, is that when the test score of a patient varies a lot, the number of test will become larger. The variables I use to do EDA are:
  * Mean, Max, and Min
  * CP: changing pattern of the test score. I first take the difference between the previous test score and next test score, then sum up the difference. If the sum-up value is larger than a specific value, then I think it shows an increasing pattern, CP = 1; if it's smaller, then I think it shows a decreasing pattern, CP = -1; if it's between, then I think the changing pattern is stable, CP = 0. This CP is similar to the ChangeStoF given by Brody.
  * numTest: came up by Brody, same meaning mentioned above.
