# Question 1 — Minimum Makespan on M Identical Servers

## Problem Statement

You are given `N` independent tasks and `M` identical servers.

Each task has a base processing time. A dispatcher assigns every task to exactly one server according to a fixed set of scheduling rules.

The dispatcher processes tasks in priority order and assigns each selected task to the server with the smallest current total load.

Servers also experience **thermal throttling**: the more tasks already assigned to a server, the larger the additional processing penalty for the next task.

After all tasks have been dispatched, determine the **makespan**, defined as the maximum final load among all servers.

---

## Scheduling Rules

### Rule 1 — Task Priority

At every step, select the **largest remaining unassigned task** according to its base processing time.

If multiple tasks have the same base processing time, select the task that appeared **earlier in the original input sequence**.

For example, if the input is:

```text
10 20 20 5
```

the dispatch order is:

```text
20 (original position 2)
20 (original position 3)
10 (original position 1)
5  (original position 4)
```

The original relative order of equal-duration tasks must be preserved.

---

### Rule 2 — Server Selection

Assign the selected task to the server with the **smallest current total load**.

Servers are numbered from `1` to `M`.

If multiple servers have the same minimum load, choose the server with the **smallest server ID**.

For example:

```text
Server 1 → 25
Server 2 → 10
Server 3 → 10
Server 4 → 30
```

The selected task must be assigned to **Server 2**.

---

### Rule 3 — Thermal Throttling

For a task with base processing time `D`, let:

- `k` = number of tasks already assigned to the selected server
- `W` = thermal penalty parameter

The actual additional processing time is:

```text
D + (k × W)
```

The server's new load becomes:

```text
new load = current load + D + (k × W)
```

For each server, `k` starts at `0`.

Therefore:

```text
1st task → penalty = 0 × W
2nd task → penalty = 1 × W
3rd task → penalty = 2 × W
4th task → penalty = 3 × W
...
```

---

## Makespan

After all `N` tasks have been assigned, calculate the final load of every server.

The **makespan** is:

```text
maximum final server load
```

Return this value.

---

# Input Format

The input consists of four lines.

### Line 1

An integer:

```text
N
```

representing the number of tasks.

### Line 2

An integer:

```text
M
```

representing the number of identical servers.

### Line 3

An integer:

```text
W
```

representing the thermal throttling penalty.

### Line 4

`N` space-separated integers:

```text
D1 D2 D3 ... DN
```

where `Di` is the base processing time of the `i`-th task in the original input sequence.

---

# Output Format

Print a single integer representing the **maximum final load of any server** after all tasks have been dispatched.

---

# Constraints

```text
1 ≤ N ≤ 100000
1 ≤ M ≤ 100
0 ≤ W ≤ 1000
1 ≤ Di ≤ 10000
```

Your solution must efficiently handle the maximum allowed value of `N`.

---

# Example 1

## Input

```text
4
2
5
10 20 20 10
```

## Dispatch Order

The tasks are processed in descending order:

```text
20, 20, 10, 10
```

The equal `20` tasks retain their original order, and the equal `10` tasks retain their original order.

Initially:

```text
Server 1 → load 0, tasks assigned 0
Server 2 → load 0, tasks assigned 0
```

### Step 1

Select `20`.

Both servers have load `0`, so choose Server 1 because it has the smaller ID.

```text
k = 0
actual time = 20 + (0 × 5)
            = 20
```

Loads:

```text
Server 1 → 20
Server 2 → 0
```

### Step 2

Select `20`.

Server 2 has the smaller load.

```text
k = 0
actual time = 20 + (0 × 5)
            = 20
```

Loads:

```text
Server 1 → 20
Server 2 → 20
```

### Step 3

Select `10`.

Both servers have load `20`, so choose Server 1.

Server 1 already has one task:

```text
k = 1
actual time = 10 + (1 × 5)
            = 15
```

Loads:

```text
Server 1 → 35
Server 2 → 20
```

### Step 4

Select `10`.

Server 2 has the smaller load.

```text
k = 1
actual time = 10 + (1 × 5)
            = 15
```

Final loads:

```text
Server 1 → 35
Server 2 → 35
```

Therefore the makespan is `35`.

## Output

```text
35
```

---

# Example 2

## Input

```text
3
1
10
5 5 5
```

There is only one server.

All three tasks have the same duration, so their original order is preserved.

### Task 1

```text
D = 5
k = 0
actual time = 5 + (0 × 10)
            = 5
```

Load:

```text
5
```

### Task 2

```text
D = 5
k = 1
actual time = 5 + (1 × 10)
            = 15
```

Load:

```text
20
```

### Task 3

```text
D = 5
k = 2
actual time = 5 + (2 × 10)
            = 25
```

Final load:

```text
45
```

## Output

```text
45
```

---

# Example 3

## Input

```text
3
3
0
100 10 1
```

There are three servers and no thermal penalty.

The tasks are processed in descending order:

```text
100, 10, 1
```

### Task 1

Assign `100` to Server 1.

```text
Server 1 → 100
Server 2 → 0
Server 3 → 0
```

### Task 2

Servers 2 and 3 have the minimum load.

Tie → choose Server 2.

```text
Server 1 → 100
Server 2 → 10
Server 3 → 0
```

### Task 3

Assign `1` to Server 3.

Final loads:

```text
Server 1 → 100
Server 2 → 10
Server 3 → 1
```

The makespan is `100`.

## Output

```text
100
```

---

# Important Clarifications

1. Tasks are selected by **largest base processing time**, not by effective processing time.

2. Equal-duration tasks must be processed in their **original input order**.

3. Server selection is based on the **current total load**, including all thermal penalties already added.

4. If multiple servers have the same current load, select the server with the **smallest server ID**.

5. Thermal penalty depends on the number of tasks **already assigned to that particular server**.

6. The first task assigned to any server has `k = 0`.

7. The penalty is calculated before incrementing the server's task count.

8. The required output is the **maximum final server load**.

---

# Task

Implement the required function to simulate the dispatcher exactly according to the rules above and return the final **makespan**.

Your solution must be efficient enough for:

```text
N = 100000
```
