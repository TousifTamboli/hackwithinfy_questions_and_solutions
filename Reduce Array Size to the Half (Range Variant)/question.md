## Reduce Array Size to the Half (Range Variant)

You are given an integer array `arr` of even length.

Choose a single contiguous range of integer values `[X, Y]` (with `X <= Y`) and remove every element of `arr` whose value lies in that range, inclusive.

Return the minimum possible length of the chosen range, `Y - X + 1`, such that at least half of the elements of `arr` are removed (the remaining size is at most `arr.length / 2`).

**Example 1:**

**Input:** `arr = [2,3,3,3,5,6]`

**Output:** `1`

**Explanation:**

* We must remove at least 3 elements.
* Choosing `[X, Y] = [3, 3]` removes all three 3s, so the remaining array is `[2,5,6]`.
* The range length is `3 - 3 + 1 = 1`, which is the smallest possible.

**Example 2:**

**Input:** `arr = [1,1,5,5,9,9]`

**Output:** `5`

**Explanation:**

* We must remove at least 3 elements, but no single value occurs 3 times.
* Range `[1, 5]` removes the four elements `1,1,5,5`, with length `5 - 1 + 1 = 5`. Range `[5, 9]` also works with length 5.
* Any range of length 4 or less covers at most one of the values 1, 5, 9, so it removes only 2 elements.
* Thus, the answer is 5.

**Example 3:**

**Input:** `arr = [1,2,3,4]`

**Output:** `2`

**Explanation:**

* We must remove at least 2 elements, and every value occurs once.
* Range `[1, 2]` removes two elements, so the length is 2.
* A range of length 1 removes only one element, which is not enough.

**Constraints:**

* `2 <= arr.length <= 10^5`
* `arr.length` is even
* `1 <= arr[i] <= 10^9`

---

