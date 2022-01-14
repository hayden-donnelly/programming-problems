# Tandem Bicycle
Problem is from the Canadian Computing Competition's online grader.\
Time limit: 3 seconds.\
All test cases passed.

## Problem Description
Since time immemorial, the citizens of Dmojistan and Pegland have been at war. Now, they have finally signed a truce. They have decided to participate in a tandem bicycle ride to celebrate the truce. There are N citizens from each country. They must be assigned to pairs so tht each pair contains one person from Dmojistan and one person from Pegland.

Each citizen has a cycling speed. In a pair, the fastest person will always operate the tandem bicycle while the slower person simply enjoys the ride. In other words, if the members of a pair have speeds a and b, then the bike speed of the pair is max(a, b). The total speed is the sum of the N individual bike speeds.

For this problem, in each test case, you will be asked to answer one of two questions:

• Question 1: what is the minimum total speed, out of all possible assignments into pairs?

• Question 2: what is the maximum total speed, out of all possible assignments into pairs?

## Input Specification
The first line will contain the type of question you are to solve, which is either 1 or 2.

The second line contains N (1 ≤ N ≤ 100).

The third line contains N space-separated integers: the speeds of the citizens of Dmojistan.

The fourth line contains N space-separated integers: the speeds of the citizens of Pegland.

Each person's speed will be an integer between 1 and 1 000 000.

For 8 of the 15 available marks, questions of type 1 will be asked. For 7 of the 15 available marks, questions of type 2 will be asked.

## Output Specification
Output the maximum or minimum total speed that answeres the questions asked.

## Sample Input 1
```
1
3
5 1 4
6 2 4
```

## Output for Sample Input 1
```
12
```

## Explanation for Output for Sample Input 1
There is a unique optimal solution:

• Pair the citizen from Dmojistan with speed 5 and the citizen from Pegland with speed 6.

• Pair the citizen from Dmojistan with speed 1 and the citizen from Pegland with speed 2.

• Pair the citizen from Dmojistan with speed 4 and the citizen from Pegland with speed 4.

## Sample Input 2
```
2
3
5 1 4
6 2 4
```

## Output for Sample Input 2
```
15
```

## Explanation for Output for Sample Input 2
There are multiple possible optimal solutions. Here is one optimal solution:

• Pair the citizen from Dmojistan with speed 5 and the citizen from Pegland with speed 2.

• Pair the citizen from Dmojistan with speed 1 and the citizen from Pegland with speed 6.

• Pair the citizen from Dmojistan with speed 4 and the citizen from Pegland with speed 4.

## Sample Input 3
```
2
5
202 177 189 589 102
17 78 1 496 540
```

## Output for Sample Input 3
```
2016
```

## Explanation for Output for Sample Input 3
There are multiple possible optimal solutions. Here is one optimal solution:

• Pair the citizen from Dmojistan with speed 202 and the citizen from Pegland with speed 1.

• Pair the citizen from Dmojistan with speed 177 and the citizen from Pegland with speed 540.

• Pair the citizen from Dmojistan with speed 189 and the citizen from Pegland with speed 17.

• Pair the citizen from Dmojistan with speed 589 and the citizen from Pegland with speed 78.

• Pair the citizen from Dmojistan with speed 102 and the citzen from Pegland with speed 496.

This sum yields 202 + 540 + 189 + 589 + 496 = 2016.

