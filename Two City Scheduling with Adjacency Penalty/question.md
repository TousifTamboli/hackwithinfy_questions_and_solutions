## Two City Scheduling with Adjacency Penalty

There are `N` candidates standing in a line (`N` is even). Candidate `i` costs `costs[i][0]` if assigned to City A and `costs[i][1]` if assigned to City B.

Assign exactly `N / 2` candidates to City A and the remaining `N / 2` to City B. Whenever two adjacent candidates (`i` and `i + 1`) are assigned to the **same** city, a penalty of `P` is incurred.

Return the minimum possible value of (total assignment cost + total penalty).

**Example 1:**

**Input:** `costs = [[1,100],[1,100],[100,1],[100,1]], P = 10`

**Output:** `24`

**Explanation:**

* Assign candidates `0, 1` to City A (cost `1 + 1 = 2`) and candidates `2, 3` to City B (cost `1 + 1 = 2`).
* The same-city adjacent pairs are `(0,1)` and `(2,3)`, so the penalty is `2 * 10 = 20`.
* The total is `2 + 2 + 20 = 24`.
* Alternating `A B A B` has no penalty but costs `1 + 100 + 100 + 1 = 202`.

**Example 2:**

**Input:** `costs = [[5,5],[5,5]], P = 3`

**Output:** `10`

**Explanation:**

* Assign candidate `0` to City A and candidate `1` to City B.
* The cost is `5 + 5 = 10` and there is no same-city adjacent pair.

**Example 3:**

**Input:** `costs = [[1,100],[1,100],[1,100],[1,100]], P = 1000`

**Output:** `202`

**Explanation:**

* Any valid assignment sends two candidates to each city, so the cost is always `1 + 1 + 100 + 100 = 202`.
* The assignment `A B A B` has no penalty, so the total is `202`.

**Constraints:**

* `2 <= N <= 1000`, `N` is even
* `1 <= costs[i][j] <= 10^4`
* `0 <= P <= 10^4`