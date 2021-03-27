
import pandas
import numpy

def getLastandTimesTested(nums, maxLength):
  nums = numpy.array(nums)
  i = 0
    
  while((not numpy.isnan(nums[i])) and i != maxLength):
    i += 1
    
  if (numpy.isnan(nums[i])):
    return nums[i - 1], i
  else:
    return nums[i], i + 1

def addEDACols(df, response, firstIdx, secondIdx):
  length = df.shape[0]
  maxLength = secondIdx - firstIdx
  df["outcome"] = numpy.array(response.iloc[df[0]-1,:]["outcome"])

  means = numpy.zeros(length)
  maxs = numpy.zeros(length)
  mins = numpy.zeros(length)
  first = numpy.zeros(length)
  last = numpy.zeros(length)
  numTests = numpy.zeros(length)

  for i in range(length):
    means[i] = numpy.mean(df.iloc[i,firstIdx:(secondIdx+1)])
    maxs[i] = numpy.max(df.iloc[i,firstIdx:(secondIdx+1)])
    mins[i] = numpy.min(df.iloc[i,firstIdx:(secondIdx+1)])
    first[i] = df.iloc[i,firstIdx]
    last[i], numTests[i] = getLastandTimesTested(df.iloc[i,firstIdx:(secondIdx+1)], maxLength)

  df["means"] = means
  df["max"] = maxs
  df["min"] = mins
  df["range"] = df["max"] - df["min"]
  df["ChangeStoF"] = last - first
  df["numTests"] = numTests



