## Street Lamps with a Generator Truck

A dead-end service road has `N` posts in a line, numbered from `1` to `N`. A street lamp installed on post `i` lights posts `i - 1`, `i` and `i + 1` (those that exist). Every post must be lit.

You are given a string `z` of length `N` consisting of `L` (live) and `D` (dead):

* A lamp can be installed only on a live post.
* A dead post cannot hold a lamp, but it must still be lit by a neighbouring lamp or by the generator truck.

You also have **at most one** generator truck that can be parked at any post (live or dead). The truck lights its own post and both immediate neighbours, exactly like a lamp, but it does **not** count towards the lamp cost.

Return the minimum number of lamps required to light all `N` posts, or `-1` if it is impossible even with the generator truck.

**Input Format:**

* Line 1: integer `N`
* Line 2: string `z`

**Function Signature:** `long long solve(int N, string z)`

**Example 1:**

**Input:** `N = 6, z = "LLDDLL"`

**Output:** `1`

**Explanation:**

* Park the truck on post `2`, which lights posts `1, 2, 3`.
* Install one lamp on post `5`, which lights posts `4, 5, 6`.
* The truck alone lights only 3 posts, so at least one lamp is needed.

**Example 2:**

**Input:** `N = 5, z = "DDDDD"`

**Output:** `-1`

**Explanation:**

* No lamp can be installed because every post is dead.
* The truck lights at most 3 posts, so the 5 posts cannot all be lit.

**Example 3:**

**Input:** `N = 6, z = "LDDDDL"`

**Output:** `2`

**Explanation:**

* Lamps on posts `1` and `6` light posts `1, 2` and `5, 6`.
* The truck on post `3` lights posts `2, 3, 4`, so every post is lit.
* One lamp plus the truck can light at most 5 posts, so one lamp is not enough.

**Constraints:**

* `1 <= N <= 10^5`
* `z[i]` is either `L` or `D`