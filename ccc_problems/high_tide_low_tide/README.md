# High Tide, Low Tide
Problem is from the Canadian Computing Competition's online grader.\
Time limit: 1 second.\
10/15 test cases passed.

## Problem Description
Joe Coder is camping near the Bay of Fundy between Nova Scotia and New Brunswick. When he arrived at the bay, he was told that the difference in height between high tide and low tide at the Bay of Fundy was the largest tidal difference in the world. Ever the skeptic, joe decided to verify this. He chose a reference point and, after learning from the radio when the tides were highest and lowest, he went with a boat to his reference point and measured the depth of the water. Unfortunately, on the last day of his trip, a strong wind scattered his measurements.

Joe has recovered all of his measurements, but they may not be in their original order. Luckily, he remembers some things about his measurements:

• He started measuring water levels at a low tide, his second measurement was of the water level at high tide, and after that the measurements continued to alternate between low and high tides.

• All high tide measurements were higher than all low tide measurements.

• Joe noticed that as time passed, the high tides only became higher and the low tides only became lower.

Given Joe's measurements in no particular order, you must reconstruct the correct order in which the measurements were taken.

## Input Specification
The first line contains the integer N (1 ≤ N ≤ 200). The next line contains N distinct space-separated positive integers, where each integer is at most 1 000 000.

## Output Specification
Output the N integers in the unique order that Joe originally took the measurements.

## Sample Input
```
8
10 50 40 7 3 110 90 2
```

## Output for Sample Input
```
10 40 7 50 3 90 2 110
```
## Explanation of Output for Sample Input
The low tide measurements (in order) were 10, 7, 3 and 2. The high tide measurments (in order) were 40, 50, 90 and 110.