# Arithmetic Square

## Problem Description
You are given a 3 x 3 grid which contains integers.

Some of the 9 elements in the grid will have a value already, and the remaining elements will be unspecified.

Your task is to determine values for the unsepcified elements such that each row, when read from left-to-right is an arithmetic sequence, and that each column, when read from the top down, is an arithmetic sequence.

Recall that an arithmetic sequence of length three is a sequence of integers of the form
```
a, a + d, a + 2d
```
for integer values of a and d. Note that d may be any integr, including zero or a negative integer.

## Input Specification
The input will be 3 lines long. Each line will have three space-separated values. Each value will either be an integer in the range from -1 000 000 to 1 000 000 to 1 000 000, inclusive, or the symbol X.

For 4 of the 15 marks available, there will be at most 3 x symbols in the input.

For an additional 3 of the 15 marks available, all integer values in the input will be between -10 and 10, inclusive.

For an additional 4 of the 15 marks available, there will be at least 7 x symbols in the input.

For an additional 2 of the 15 marks available, all inteer values in the input will be even numbers.

## Output Specification
The output will be 3 lines long. Each line will have three space-separated integers. All integers that were given in the input must be in their same position (i.e., same row and same column as in the input). All rows and columns must form arithmetic sequences. All integers in the output must be between -1 000 000 000 and 1 000 000 000, inclusive.

If there is more than one solution, output any solution. There is guaranteed to be at least one solution.

## Sample Input 1
```
8 9 10
16 x 20
24 x 30
```

## Output for Sample Input 1
```
8 9 10
16 18 20
24 27 30
```

## Explanation of Output for Sample Input 1
Notice that the second element of the second row must be 16 + t and since 20 = 16 + 2t, then t = 2, and thus, this unspecified element must be 18. A similar argument applies to the second element of the third row.

## Sample Input 2
```
14 x x
x x 18
x 16 x
```

## Possible Output for Sample Input
```
14 20 26
18 18 18
22 16 10
```

## Explanation of Output for Sample Input 2
This is one of many possible solutions. For example, another solution is:
```
14 16 18
14 16 18
14 16 18
```