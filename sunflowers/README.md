# Sunflowers
Problem is from the Canadian Computing Competition's online grader.\
Time limit: 1 second.\
All test cases passed.

## Problem Description
Barbara plants N different sunflowers, each with a unique height, order from smalles to largest,
and records thei heights for N consecutive days. Each day, all of her flowers grow taller than there were the day before.

She records each of these measurements in a table, with one row for each plant, with the first row recording the shortest sunflower's growth and the last row recording the tallest sunflower's growth. The leftmost column is the first measurement for each sunflower, and the rightmost column is the last measurement for each sunflower.

If a sunflower was smaller than another when initially planted, it remains smaller for every measurement.

Unfortunately, her children may have altered her measurements by rotating her table by a multple of 90 degrees.

Your job is to help Barbara determine her original data.

## Input Specification
The first line of input contains the number N (2 ≤ N ≤ 100). The next N lines each contain N positive integers,
each of which is at most 10<sup>9</sup>. It is guaranteed that the input grid represents a rotated version of Barbara's grid.

## Output Specification
Output Barbara's original data, consisting of N lines, each of which contain N positive integers.

## Sample Input 1
```
2
1 3
2 9
```

## Output for Sample Input 1
```
1 3
2 9
```

## Explanation of Output for Sample Input 1
The data has been rotated a multiple of 360 degrees, meaning that the input arrangement is the original arrangment.

## Sample Input 2
```
3
4 3 1
6 5 2
9 7 3
```

## Explanation of Output for Sample Input 2
The original data was rotated 90 degrees to the right/clockwise.