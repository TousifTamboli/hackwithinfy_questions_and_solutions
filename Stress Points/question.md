# Problem 2: Stress Points

### Description

You are given an integer array `arr` of length `n`.

An index `i` is called a **stress point** if:

```text
arr[i] > arr[i - 1] && arr[i] > arr[i + 1]
```

In other words, an element is a stress point if it is **strictly greater than both of its immediate neighbors**.

The first and last elements cannot be stress points because they have only one neighbor.

Return the **total number of stress points** in the array.

### Constraints

* `3 <= arr.length <= 10^5`
* `-10^9 <= arr[i] <= 10^9`

### Test Cases

**Example 1:**

```text
Input: arr = [1, 3, 2, 4, 1]
Output: 2
```

**Example 2:**

```text
Input: arr = [5, 5, 3, 6, 2, 7, 7]
Output: 2
```

**Example 3:**

```text
Input: arr = [1, 2, 1, 3, 2, 4, 1]
Output: 3
```

### Explanation for Example 3

The stress points are:

```text
[1, 2, 1, 3, 2, 4, 1]
    ↑     ↑     ↑
    2     3     4
```

Each highlighted element is greater than both of its neighbors, so the answer is `3`.
