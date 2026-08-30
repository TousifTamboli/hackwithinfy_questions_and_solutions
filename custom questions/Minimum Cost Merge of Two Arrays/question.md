# Minimum Cost Merge of Two Arrays

## Problem Statement

You are given two arrays `A` and `B` of lengths `m` and `n`, respectively.

You have to **merge** these two arrays into a single array while maintaining the **relative order** of elements within each original array.

In other words:

* The elements of `A` must appear in the same order as they originally did.
* The elements of `B` must appear in the same order as they originally did.
* You can choose at each step whether to take the next element from `A` or from `B`.

There can be many possible valid merged arrays.

For example, if:

```text
A = [1, 2]
B = [3, 4]
```

Some valid merges are:

```text
[1, 2, 3, 4]
[1, 3, 2, 4]
[1, 3, 4, 2]
[3, 1, 2, 4]
[3, 1, 4, 2]
[3, 4, 1, 2]
```

All of these maintain the relative order of both arrays.

---

## Cost Definition

You are also given a 2D cost matrix `C`.

For any two consecutive elements `x` and `y` in the merged array, the cost of moving from `x` to `y` is:

```text
C[x][y]
```

Therefore, if the merged array is:

```text
[x1, x2, x3, ..., xk]
```

its total cost is:

```text
C[x1][x2] + C[x2][x3] + ... + C[x(k-1)][xk]
```

Your task is to find the **minimum possible cost** among all valid ways of merging the two arrays.

---

## Example

Consider:

```text
A = [1, 2]
B = [3, 4]
```

and the cost matrix:

```text
    1  2  3  4
1   1  3  2  1
2   7  2  6  4
3   1  3  4  5
4   1  1  2  3
```

### Merge 1

```text
[1, 2, 3, 4]
```

Cost:

```text
C[1][2] + C[2][3] + C[3][4]

= 1 + 6 + 5

= 12
```

### Merge 2

```text
[1, 3, 2, 4]
```

Cost:

```text
C[1][3] + C[3][2] + C[2][4]

= 2 + 3 + 4

= 9
```

### Merge 3

```text
[1, 3, 4, 2]
```

Cost:

```text
C[1][3] + C[3][4] + C[4][2]

= 2 + 5 + 1

= 8
```

### Merge 4

```text
[3, 1, 2, 4]
```

Cost:

```text
C[3][1] + C[1][2] + C[2][4]

= 1 + 1 + 4

= 6
```

### Merge 5

```text
[3, 1, 4, 2]
```

Cost:

```text
C[3][1] + C[1][4] + C[4][2]

= 1 + 1 + 1

= 3
```

### Merge 6

```text
[3, 4, 1, 2]
```

Cost:

```text
C[3][4] + C[4][1] + C[1][2]

= 5 + 1 + 1

= 7
```

Therefore, the minimum cost is:

```text
3
```

and one optimal merged array is:

```text
[3, 1, 4, 2]
```

---

## Input Format

The input consists of:

```text
m n
A[1] A[2] ... A[m]
B[1] B[2] ... B[n]
C[1][1] C[1][2] ... C[1][k]
C[2][1] C[2][2] ... C[2][k]
...
C[k][1] C[k][2] ... C[k][k]
```

where `k` is the maximum possible value of an element in either array.

---

## Output Format

Print a single integer representing the **minimum possible cost** among all valid merges of the two arrays.

---

## Constraints

* `1 <= m, n <= 1000`
* `1 <= A[i], B[i] <= 2000`
* `1 <= C[i][j] <= 10^9`
* The elements of both arrays are valid indices of the cost matrix.
* The relative order of elements in each array must be preserved.
* The answer may be large, so use a 64-bit integer type such as `long long` in C++.

---

## Important Observation

The number of possible merges can be very large.

For arrays of lengths `m` and `n`, the number of valid merges is:

```text
C(m + n, m)
```

For example, if:

```text
m = n = 1000
```

the number of possible merges is astronomically large.

Therefore, **generating every possible merge is not feasible**.

You must find an efficient algorithm.

---

## Expected Complexity

An efficient solution should run in approximately:

```text
Time:  O(m * n)
Space: O(m * n)
```

An optimized solution may reduce the space complexity to:

```text
O(n)
```

while maintaining `O(m * n)` time complexity.

---

## Example Input

```text
2 2
1 2
3 4
1 3 2 1
7 2 6 4
1 3 4 5
1 1 2 3
```

## Example Output

```text
3
```

## Explanation

The minimum-cost valid merge is:

```text
[3, 1, 4, 2]
```

Its cost is:

```text
C[3][1] + C[1][4] + C[4][2]

= 1 + 1 + 1

= 3
```

No other valid merge has a smaller cost.

---

## Task

Write an algorithm that finds the **minimum possible cost** of merging the two arrays while preserving the relative order of elements in both arrays.
