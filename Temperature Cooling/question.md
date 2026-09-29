Sure. Here are the same questions with the **answers for all 3 test cases**.

## Problem 1: Temperature Cooling

### Description

You are given an integer array `temperature` of length `n`, where `temperature[i]` represents the temperature at position `i`.

Your goal is to reduce every temperature to `0`.

You can perform the following operations:

1. **Cool by 1°C:**
   Decrease the temperature of an element by `1`. This operation takes **1 unit of time**.

2. **Blast:**
   Choose an index `i` and perform a blast:

   * `temperature[i]` becomes `0` immediately.
   * Any remaining/residual temperature at index `i` is carried to the element immediately to its right, `i + 1`.
   * The blast itself takes `0` units of time.
   * You can perform blasts at multiple indices.

Return the **minimum total cooling time** required to reduce the entire array to `0`.

### Constraints

* `1 <= temperature.length <= 10^5`
* `0 <= temperature[i] <= 10^9`

### Test Cases

**Example 1:**

```text
Input: temperature = [2, 3, 1]
Output: 6
```

**Example 2:**

```text
Input: temperature = [5, 1, 4, 2]
Output: 12
```

**Example 3:**

```text
Input: temperature = [1, 2, 3, 4]
Output: 10
```

