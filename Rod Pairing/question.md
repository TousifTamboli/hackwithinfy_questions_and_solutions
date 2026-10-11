## Rod Pairing

You are given `n` rods. Rod `i` has length `length[i]` and material type `material[i]`, which is either `0` or `1`.

Form pairs so that each pair contains exactly one rod of material `0` and one rod of material `1`, and each rod is used in at most one pair. The value of a pair is the minimum of its two rod lengths.

Return the maximum possible total value of all pairs, modulo `10^9 + 7`.

**Example 1:**

**Input:** `length = [10,20,30,10,20], material = [0,1,0,1,1]`

**Output:** `30`

**Explanation:**

* Material 0 rods have lengths `[30, 10]` and material 1 rods have lengths `[20, 20, 10]` (sorted in descending order).
* Pair `30` with `20` (value `20`) and `10` with `20` (value `10`).
* The total is `20 + 10 = 30`. The extra rod of length `10` stays unused.

**Example 2:**

**Input:** `length = [5,5,5], material = [0,0,0]`

**Output:** `0`

**Explanation:**

* There are no rods of material `1`, so no pair can be formed.

**Example 3:**

**Input:** `length = [9,1,8,2,7], material = [0,0,1,1,1]`

**Output:** `9`

**Explanation:**

* Material 0 rods have lengths `[9, 1]` and material 1 rods have lengths `[8, 7, 2]` (sorted in descending order).
* Pair `9` with `8` (value `8`) and `1` with `7` (value `1`).
* The total is `8 + 1 = 9`.

**Constraints:**

* `1 <= n <= 10^5`
* `1 <= length[i] <= 10^9`
* `material[i]` is `0` or `1`