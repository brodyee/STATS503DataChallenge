# EDA on each `var.csv`

* Brody's EDA: I didn't find many particular statistics/engineered variables that split the outcome well. After a little thought, this is not surprising. Because one variable is probably not going to split it well. So, it is probably best to come up with a few statistics/engineered variables that we think would magnify something that may be important. Here are the variables that I came up with:
  * Mean, Max, Min, and Range: Not much explanation needed
  * ChangeStoF: Simular to range, but (instead of max - min) it is last test minus first test. This is to try to capture the change over time. If it is a linear change over time, then range ~= ChangeStoF. However, if it is a non-linear change, then range != ChangeStoF.
  * numTest: This may or may not be helpful. It seems that for some test, being tested a lot may be a sign that one is/is not recovering. It will be interesting to see if this helps. 
