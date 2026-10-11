## Split Array by Tension

You are given an integer array `arr` and an integer `MaxTension`.

Split the array into contiguous subarrays. The **tension** of a subarray is (sum of its elements) + (maximum element of the subarray). Every subarray must have tension at most `MaxTension`.

Return the minimum number of splits (cuts) needed.

**Example 1:**

**Input:** `arr = [5,5,10,5], MaxTension = 20`

**Output:** `2`

**Explanation:**

* `[5,5]` has tension `10 + 5 = 15`, but adding `10` gives `20 + 10 = 30 > 20`, so we cut here.
* `[10]` has tension `20`, but adding the last `5` gives `15 + 10 = 25 > 20`, so we cut again.
* The result is `[5,5] | [10] | [5]`, which uses 2 splits.

**Example 2:**

**Input:** `arr = [6,2,3,9,1], MaxTension = 19`

**Output:** `1`

**Explanation:**

* `[6,2,3]` has tension `11 + 6 = 17`, but adding `9` gives `20 + 9 = 29 > 19`, so we cut.
* `[9,1]` has tension `10 + 9 = 19`, which is allowed.
* The result is `[6,2,3] | [9,1]`, which uses 1 split.

**Example 3:**

**Input:** `arr = [1,2,3], MaxTension = 100`

**Output:** `0`

**Explanation:**

* The whole array has tension `6 + 3 = 9`, which is within the limit, so no split is needed.

**Constraints:**

* `1 <= arr.length <= 10^5`
* `1 <= arr[i] <= 10^9`
* `2 * arr[i] <= MaxTension` for every `i` (so a valid split always exists)