# Question 1 — Car Pooling

## Problem Statement

You are driving a bus with a maximum capacity of available seats. The bus travels strictly east, picking up and dropping off passengers.

You are given a 2D array `trips`, where each `trips[i] = [numPassengers, from, to]` indicates that `numPassengers` board the bus at location `from` and leave at location `to`.

The bus will always allow passengers to board, even if it exceeds the number of available seats. If the number of passengers on the bus between any location `x` and `x + 1` exceeds the `capacity`, the excess passengers must stand.

Calculate the total **"standing passenger-kilometers"** across the entire journey.

For example, if 3 passengers are forced to stand for 2 units of distance, that adds `6` to the total.

Find the **total standing passenger-kilometers**.

---

## Input Format

The input consists of the following:

1. The first line contains an integer `T`, denoting the number of trips.
2. The second line contains an integer `capacity`, denoting the maximum number of passengers that can be seated.
3. Each of the next `T` lines contains 3 space-separated integers representing one trip:
   - `numPassengers` — the number of passengers in the trip.
   - `from` — the starting location where the passengers board the bus.
   - `to` — the destination location where the passengers leave the bus.

Each trip is represented as:

```text
[numPassengers, from, to]
```

---

## Constraints

- `1 ≤ T ≤ 1000`
- `1 ≤ capacity ≤ 10^5`
- `0 ≤ trips[i][j] ≤ 1000`

---

## Examples

### Example 1

#### Input

```text
2
4
3 1 5
2 3 7
```

#### Output

```text
2
```

#### Explanation

There are `2` trips and the bus capacity is `4`.

The trips are:

- `3` passengers from location `1` to location `5`
- `2` passengers from location `3` to location `7`

From location `1` to `3`, there are `3` passengers on the bus.

Since `3` is less than the capacity of `4`, no passengers need to stand.

From location `3` to `5`, the second group boards. There are now `5` passengers on the bus.

Since `5` exceeds the capacity of `4`, `1` passenger must stand.

This passenger stands for `2` kilometers, from location `3` to location `5`, contributing:

```text
1 × 2 = 2
```

standing passenger-kilometers.

From location `5` to `7`, the first group leaves, leaving `2` passengers on the bus. No passengers need to stand.

Therefore, the total standing passenger-kilometers are:

```text
2
```

### Example 2

#### Input

```text
3
5
2 0 3
1 1 4
2 3 5
```

#### Output

```text
0
```

#### Explanation

The bus never has more than `5` passengers at any point in the journey.

From location `0` to `1`, there are `2` passengers on the bus.

From location `1` to `3`, there are `3` passengers on the bus.

From location `3` to `4`, the third trip starts and the first trip ends, leaving `3` passengers on the bus.

From location `4` to `5`, only `2` passengers remain.

No passengers ever need to stand, so the total standing passenger-kilometers are:

```text
0
```

### Example 3

#### Input

```text
3
3
2 1 4
2 2 5
1 3 6
```

#### Output

```text
3
```

#### Explanation

From location `1` to `2`, there are `2` passengers on the bus.

From location `2` to `3`, there are `4` passengers on the bus, so `1` passenger must stand for `1` unit of distance.

From location `3` to `4`, there are `5` passengers on the bus, so `2` passengers must stand for `1` unit of distance.

From location `4` to `5`, the first trip ends and `3` passengers remain, which fits the capacity.

From location `5` to `6`, only `1` passenger remains.

Therefore, the total standing passenger-kilometers are:

```text
3
```

### Example 4

#### Input

```text
4
6
5 0 3
4 1 5
2 2 4
3 4 6
```

#### Output

```text
9
```

#### Explanation

From location `0` to `1`, there are `5` passengers on the bus.

From location `1` to `2`, there are `9` passengers on the bus, so `3` passengers must stand for `1` unit of distance.

From location `2` to `3`, there are `11` passengers on the bus, so `5` passengers must stand for `1` unit of distance.

From location `3` to `4`, the first trip ends and the bus carries exactly `6` passengers, so no one stands.

From location `4` to `5`, the fourth trip begins and the third trip ends, leaving `7` passengers on the bus, so `1` passenger must stand for `1` unit of distance.

From location `5` to `6`, only `3` passengers remain.

Therefore, the total standing passenger-kilometers are:

```text
9
```

---

## Task

Implement the following function:

```cpp
int solve(int T, int capacity, vector<vector<int>>& trips)
```

Return the total number of **standing passenger-kilometers** accumulated throughout the journey.
