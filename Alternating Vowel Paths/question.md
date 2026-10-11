## Alternating Vowel Paths

You are given an integer `n`.

Count the strings of length `n` that consist only of the lowercase vowels `a, e, i, o, u` and satisfy both conditions:

* **Transition rules:** every pair of consecutive characters must be an allowed transition: `a → e`, `e → a, i`, `i → a, e, o, u`, `o → i, u`, `u → a`.
* **Alternation:** every transition is either an **up** move (to a lexicographically greater letter) or a **down** move (to a lexicographically smaller letter). Two consecutive transitions must have **different** directions.

Return the number of valid strings modulo `10^9 + 7`.

**Example 1:**

**Input:** `n = 1`

**Output:** `5`

**Explanation:**

* A single character has no transitions, so every vowel is valid: `a, e, i, o, u`.

**Example 2:**

**Input:** `n = 2`

**Output:** `10`

**Explanation:**

* There is only one transition, so no alternation check applies. Every allowed transition counts.
* The number of allowed transitions is 1 (from `a`) + 2 (`e`) + 4 (`i`) + 2 (`o`) + 1 (`u`) = 10.

**Example 3:**

**Input:** `n = 3`

**Output:** `12`

**Explanation:**

* The valid strings are: `aea, eae, eia, eie, iae, iei, ioi, iua, oio, oiu, oua, uae`.
* For example, `eia` is valid because `e → i` is up and `i → a` is down.
* `eio` is invalid because `e → i` and `i → o` are both up moves.

**Constraints:**

* `1 <= n <= 10^5`

---

