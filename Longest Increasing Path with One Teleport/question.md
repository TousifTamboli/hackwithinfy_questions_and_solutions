## Longest Increasing Path with One Teleport

You are given an `N x M` matrix of integers.

Find the longest path, where the length of a path is the number of cells it visits. From a cell you may:

* move up, down, left or right to a neighbouring cell whose value is **strictly greater** than the current cell's value, or
* use a **teleport** to jump to any cell in the matrix (adjacent or not) whose value is strictly greater than the current cell's value.

The teleport may be used **at most once** during the whole path.

Return the maximum possible path length.

**Example 1:**

**Input:** `matrix = [[1,9],[2,10]]`

**Output:** `4`

**Explanation:**

* Start at `1`, move down to `2`, teleport to `9`, then move down to `10`.
* The path `1 -> 2 -> 9 -> 10` visits 4 cells.
* Without the teleport, the longest path has only 3 cells.

**Example 2:**

**Input:** `matrix = [[9,1,5],[8,2,6],[7,3,4]]`

**Output:** `8`

**Explanation:**

* Start at `1` and move down through `2, 3` to `4`, then move up to `6`.
* Teleport from `6` to `7`, then move up to `8` and `9`.
* The path `1 -> 2 -> 3 -> 4 -> 6 -> 7 -> 8 -> 9` visits 8 cells.

**Example 3:**

**Input:** `matrix = [[5,5],[5,5]]`

**Output:** `1`

**Explanation:**

* No cell has a strictly greater neighbour or a strictly greater cell to teleport to, so the best path is a single cell.

**Constraints:**

* `1 <= N, M <= 100`
* `1 <= matrix[i][j] <= 10^6`