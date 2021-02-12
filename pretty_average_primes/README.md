# Pretty Average Primes
Problem is from the Canadian Computing Competition's online grader.\
Time limit: 1 seconds.\

## Problem Description
For various given positive integers N > 3, find two primes, A and B such that N is the average (mean)
of A and B. That is, N should be equal to (A + B)/2.

Recal that a prime number is an integer P > 1 which is only divisible by 1 and P. For example,
2, 3, 5, 7, 11 are the first few primes, and 4, 6, 8, 9 are not prime numbers.

## Input Specification
The first line of input is the number T (1 ≤ T ≤ 1 000), which is the number of test cases. Each of the next T lines contain one integer N<sub>i</sub> (4 ≤ N<sub>i</sub> ≤ 1 000 000, 1 ≤ i ≤ T).

For 6 of the 15 available marks, all N<sub>i</sub> < 1 000.

## Output Specification
The output will consist of T lines. The ith line of output will contan two integers, A<sub>i</sub> and
B<sub>i</sub>, separated by one space. It should be the case that N<sub>i</sub> = (A<sub>i</sub> + 
B<sub>i</sub>)/2 and that A<sub>i</sub> and B<sub>i</sub> are prime numbers.

If there are more than one possible A<sub>i</sub> and B<sub>i</sub> for a particular N<sub>i</sub>,
output any such pair. The order of the pair A<sub>i</sub> and B<sub>i</sub> does not matter.

It will be the case that there will always be at least one set of values A<sub>i</sub> and B<sub>i</sub>
for any given N<sub>i</sub>.

## Sample Input
```
4
8
4
7
21
```

## Possible Output for Sample Input
```
3 12
5 3
7 7
13 29
```
