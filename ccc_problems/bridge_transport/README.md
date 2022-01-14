# Bridge Transport
Problem is from the Canadian Computing Competition's online grader.\
Time limit: 1 second.\
12/15 test cases passed.

## Problem Description
A train of railway cars attempts to cross a bridge. The lenght of each car is 10m but their weights might be different. The brdige is 40m long (thus can hold 4 train cars at one time). The bridge will crack if the total weight of the cars on it at one time is greater than a certain weight. The cars are numbered starting at 1, going up to N, anf they cross the bridge in that order (i.e., 1 immediately followed by 2, which is immediately followed by 3, and so on).

What is th elargest number T of railway cars such that the train of cars 1...T (in order) can cross the bridge?

## Input Specification
The first line of input is the maximum weight W (1 ≤ W ≤ 100 000) that the bridge can hold at any particular time. The second line of input is the number N (1 ≤ N ≤ 100 000) which is the number of railway cars that we wish to move across the bridge. On each of the next N lines of input, there will be a positive integer w<sub>i</sub> (1 ≤ i ≤ N, 1 w<sub>i</sub> ≤ 100 000) which represents the weight of the ith railway car in the sequence.

## Output Specification
Your output should be a non-negative integer representing the maximum number of railway cars that can be brought across the bridge in the order specified.

## Sample Input 1
```
100
6
50
30
10
10
40
50
```

## Output for Sample Input 1
5

## Explanation for Output for Sample Input 1
The first four railway cars have total weight 50 + 30 + 10 + 10 = 100, which is not greater than what the birdge can hold. When the first railway car leaves, and the next comes on, we have a total weight of 30 + 10 + 10 + 40 = 90, which is not greater than what the bridge can hold. The last four cars would cause the bridge to break, since 10 + 10 + 40 + 50 = 110 which is greater than what the bridge can hold. So, only the first 5 railway cars can be taken across the bridge.

## Sample Input 2
```
100
3
150
1
1
```

## Output for Sample Input 2
```
0
```

## Explanation of Output for Sample Input 2
When the first railway car enters the brdige, its weight of 150 will exceed the maximum weight the bridge can hold. Thus, we cannot bring any railway cars across the bridge.