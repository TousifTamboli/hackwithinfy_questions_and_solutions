## Partition by Increasing Beauty

You are given an integer array `arr`.

The **beauty** of a subarray is the length of the longest strictly increasing subsequence inside that subarray.

Partition `arr` into one or more **contiguous, non-empty** subarrays such that the beauties of the subarrays, taken from left to right, are **strictly increasing**.

Return the number of such partitions.

**Example 1:**

**Input:** `arr = [1,2,3,4,5,6]`

**Output:** `4`

**Explanation:**

* `[1,2,3,4,5,6]` has beauty `6`.
* `[1] [2,3,4,5,6]` has beauties `1 < 5`.
* `[1,2] [3,4,5,6]` has beauties `2 < 4`.
* `[1] [2,3] [4,5,6]` has beauties `1 < 2 < 3`.
* Any other partition, for example `[1,2,3] [4,5,6]` (beauties `3, 3`), is not strictly increasing.

**Example 2:**

**Input:** `arr = [3,1,2]`

**Output:** `2`

**Explanation:**

* `[3,1,2]` has beauty `2`, so it is valid on its own.
* `[3] [1,2]` has beauties `1 < 2`, so it is valid.
* `[3,1] [2]` has beauties `1, 1`, and `[3] [1] [2]` has beauties `1, 1, 1`, so neither is valid.

**Example 3:**

**Input:** `arr = [5,4,3,2,1]`

**Output:** `1`

**Explanation:**

* Every subarray of a decreasing array has beauty `1`.
* Any cut would create two subarrays with equal beauty, so only the whole array works.

**Constraints:**

* `1 <= arr.length <= 2000`
* `1 <= arr[i] <= 10^9`