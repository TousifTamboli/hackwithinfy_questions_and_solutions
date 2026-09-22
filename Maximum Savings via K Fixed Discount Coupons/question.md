# Question — Maximum Savings via K Fixed Discount Coupons

## Problem Statement

You are given an array of `N` items, where the `i-th` item has a price of `P[i]`.

You hold `K` identical coupons. Each coupon provides a flat discount of `D` when applied to a single item.

The effective discount (savings) obtained from applying one coupon to an item is:

`min(P[i], D)`

This means the discount can never exceed the item's price.

Each item can receive **at most one coupon**.

You must follow the store's policy:

- Choose a **contiguous subarray of exactly `W` items**.
- Within the chosen subarray, you may apply your `K` coupons to **at most `K` different items**.
- Each selected item can receive at most one coupon.
- For every item that receives a coupon, the savings are `min(P[i], D)`.
- Your goal is to maximize the **total savings**.

Find the **maximum possible total savings** over all valid contiguous subarrays of length `W`.

Return the answer **modulo `10^9 + 7`**.

---

## Input Format

The input consists of five lines:

1. The first line contains an integer `N`, denoting the total number of items.
2. The second line contains an integer `W`, denoting the exact length of the contiguous subarray that must be chosen.
3. The third line contains an integer `K`, denoting the maximum number of coupons that can be applied within the chosen subarray.
4. The fourth line contains an integer `D`, denoting the flat discount provided by each coupon.
5. The fifth line contains `N` space-separated integers representing the price of each item, `P[i]`.

---

## Constraints

- `1 ≤ N ≤ 10^5`
- `1 ≤ W ≤ N`
- `1 ≤ K ≤ W`
- `1 ≤ D ≤ 10^9`
- `1 ≤ P[i] ≤ 10^9`

---

## Important Details

- The chosen items must form **one contiguous subarray**.
- The subarray must contain **exactly `W` items**.
- You cannot choose arbitrary items from different positions.
- You can use **at most `K` coupons**, not necessarily exactly `K`.
- A coupon can be applied to only one item.
- An item can receive **at most one coupon**.
- The savings for item `i` from one coupon is `min(P[i], D)`.
- The objective is to maximize the total savings among **all** contiguous subarrays of length `W`.
- Since the answer can be large, return it modulo `10^9 + 7`.

---

## Example 1

### Input

```text
5
3
2
10
5 15 8 20 2
```

### Output

```text
20
```

### Explanation

The prices are:

```text
[5, 15, 8, 20, 2]
```

The window size is `3`, and at most `2` coupons can be used. Each coupon has a discount of `10`.

The effective savings available for each item are:

```text
[5, 10, 8, 10, 2]
```

The possible windows are:

- Window 1: `[5, 15, 8]` → best two savings = `10 + 8 = 18`
- Window 2: `[15, 8, 20]` → best two savings = `10 + 10 = 20`
- Window 3: `[8, 20, 2]` → best two savings = `10 + 8 = 18`

Therefore, the maximum possible savings is:

```text
20
```

---

## Example 2

### Input

```text
4
2
1
5
1 2 3 4
```

### Output

```text
4
```

### Explanation

The prices are:

```text
[1, 2, 3, 4]
```

The window size is `2`, and only `1` coupon can be used. The coupon discount is `5`.

Since every price is less than `5`, the effective savings are:

```text
[1, 2, 3, 4]
```

The windows are:

- `[1, 2]` → maximum savings = `2`
- `[2, 3]` → maximum savings = `3`
- `[3, 4]` → maximum savings = `4`

Therefore, the maximum possible savings is:

```text
4
```

---

## Example 3

### Input

```text
6
4
3
100
10 20 30 40 50 60
```

### Output

```text
150
```

### Explanation

The prices are:

```text
[10, 20, 30, 40, 50, 60]
```

The window size is `4`, and at most `3` coupons can be used. Each coupon provides a discount of `100`.

Because every price is below `100`, the effective savings for each item equal its price.

The windows are:

- `[10, 20, 30, 40]` → best 3 savings = `20 + 30 + 40 = 90`
- `[20, 30, 40, 50]` → best 3 savings = `30 + 40 + 50 = 120`
- `[30, 40, 50, 60]` → best 3 savings = `40 + 50 + 60 = 150`

Therefore, the maximum possible savings is:

```text
150
```

---

## Expected Task

Implement a function that receives:

```text
N, W, K, D, P
```

and returns the maximum possible total savings obtainable by choosing a contiguous subarray of exactly `W` items and applying at most `K` coupons, subject to the rules above.

The returned result must be given modulo:

```text
10^9 + 7
```
