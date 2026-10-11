## Pizza with 3n Slices (Tolerance Tokens)

You are given a circular pizza with `3n` slices, where `slices[i]` is the size of the `i`-th slice (clockwise order). You must select **exactly** `n` slices.

Normally you cannot pick two adjacent slices. However, you have `K` Tolerance Tokens. Each time you select a slice that is immediately clockwise to another already-selected slice, you must spend `1` token. The array is circular, so slice `3n - 1` and slice `0` are also adjacent, and selecting both costs `1` token.

Return the maximum total size of exactly `n` selected slices such that the number of adjacent selected pairs does not exceed `K`.

**Input Format:**

* Line 1: integer `n`
* Line 2: integer `K`
* Next `3n` lines: `slices[i]`

**Function Signature:** `int solve(int N, int K, vector<int>& slices)`

**Example 1:**

**Input:** `n = 1, K = 0, slices = [10,20,30]`

**Output:** `30`

**Explanation:**

* We pick exactly one slice, so no adjacent pair is possible. The largest slice is `30`.

**Example 2:**

**Input:** `n = 2, K = 0, slices = [9,10,1,1,1,8]`

**Output:** `18`

**Explanation:**

* With no tokens, no two selected slices may be adjacent.
* Slices `9` and `10` are adjacent, and `9` and `8` are adjacent through the wrap-around.
* The best valid choice is `10` (index 1) and `8` (index 5), giving `18`.

**Example 3:**

**Input:** `n = 2, K = 1, slices = [9,10,1,1,1,8]`

**Output:** `19`

**Explanation:**

* Pick slices `9` and `10`. They form one adjacent pair, which costs `1` token.
* `19` is the largest possible sum of two slices, so it is optimal.

**Constraints:**

* `1 <= n <= 100`
* `0 <= K <= n`
* `1 <= slices[i] <= 1000`