# Longest Strictly Increasing Path in Grid

You are given an `N × M` grid of integers.

You want to find the **maximum possible length of a strictly increasing path**. The length of a path is defined as the **number of cells visited**.

Normally, from any cell, you can move 1 step in any of the 4 cardinal directions (**up, down, left, right**) to a neighboring cell, provided that the value in the neighboring cell is **strictly greater** than the value in your current cell.

However, to make things interesting, you are allowed to use a special **"Dash" move** at most once during your entire path.

A Dash move allows you to jump over an immediate neighboring cell to land on the cell exactly two steps away in the same direction.

For example:

```text
(i, j) → (i+2, j)
```

To perform a Dash:

1. The destination cell must be **strictly greater** than your current cell.
2. The destination cell must be within the grid boundaries.
3. The intermediate skipped cell is completely ignored:

   * Its value does not matter.
   * It is not counted as a visited cell.

Find the **maximum number of cells you can visit** on a valid path.

## Input Format

The first line contains an integer `N`, denoting the number of rows.

The second line contains an integer `M`, denoting the number of columns.

Each of the next `N` lines contains `M` space-separated integers, representing a row of the grid.

## Constraints

```text
1 <= N <= 200
1 <= M <= 200
1 <= g[i][j] <= 10^9
```

## Examples

### Example 1

#### Input

```text
3
3
1 9 2
9 9 3
9 9 4
```

#### Output

```text
5
```

#### Explanation

The optimal path starts at `(0,0)` with value `1`.

We use the Dash move to jump right over the `9` at `(0,1)` and land directly on the `2` at `(0,2)`.

From there, we move normally down to the `3` at `(1,2)`, then normally down to the `4` at `(2,2)`.

Finally, from the `4` at `(2,2)`, we can move normally to the left to the `9` at `(2,1)`, because `9` is strictly greater than `4`.

The sequence of visited cells is:

```text
1, 2, 3, 4, 9
```

The total length is `5`.

---

### Example 2

#### Input

```text
1
4
10 50 15 20
```

#### Output

```text
3
```

#### Explanation

Start at the first cell with value `10`.

Use the Dash move to jump right, passing over the `50` and landing on the `15`.

Then move normally to the right to `20`.

The path values are:

```text
10, 15, 20
```

The total number of cells visited is `3`.

---

### Example 3

#### Input

```text
2
2
5 5
5 5
```

#### Output

```text
1
```

#### Explanation

All cells have the same value. There are no strictly greater adjacent neighbors, and a Dash also requires the destination cell to be strictly greater.

Therefore, no valid move can be made from the starting cell.

The longest path consists of just the starting cell itself.

The answer is `1`.
