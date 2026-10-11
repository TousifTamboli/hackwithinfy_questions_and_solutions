## Last Stone Weight II (Resonance Variant)

You are given an integer array `stones` of length `N` and an integer `R` (the resonance value).

Assign every stone to either **Set A** or **Set B**. The total weight of a set is:

* the sum of the weights of the stones in that set, plus
* `R` for every pair of originally adjacent stones (indices `i` and `i + 1`) that are placed in the **same** set.

Return the minimum possible absolute difference between the total weight of Set A and the total weight of Set B.

**Example 1:**

**Input:** `stones = [10,20,30], R = 10`

**Output:** `10`

**Explanation:**

* Put stones 10 and 20 in Set A, and stone 30 in Set B.
* Set A = 10 + 20 + 10 (the adjacent pair is in the same set) = 40. Set B = 30.
* The difference is `|40 - 30| = 10`.
* No other assignment does better. For example, `{10,30}` vs `{20}` gives `|40 - 20| = 20`.

**Example 2:**

**Input:** `stones = [4,4,4,4], R = 2`

**Output:** `0`

**Explanation:**

* Put stones at indices 0 and 2 in Set A, and indices 1 and 3 in Set B.
* No adjacent pair shares a set, so there is no resonance bonus.
* Set A = 8 and Set B = 8, so the difference is 0.

**Example 3:**

**Input:** `stones = [1,2,3,4], R = 5`

**Output:** `2`

**Explanation:**

* Put stones 1 and 3 in Set A, and stones 2 and 4 in Set B.
* Set A = 1 + 3 = 4 and Set B = 2 + 4 = 6, with no resonance bonus, so the difference is 2.
* Putting any adjacent pair in the same set adds 5, which makes the difference larger. The minimum is 2.

**Constraints:**

* `1 <= N <= 100`
* `1 <= stones[i] <= 100`
* `0 <= R <= 100`