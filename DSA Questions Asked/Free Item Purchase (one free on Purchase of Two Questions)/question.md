## Question — Free Item Purchase

You are given an array `cost` of `N` items, where `cost[i]` represents the price of the `i`-th item.

You want to purchase all `N` items while minimizing the total amount of money you pay.

You are allowed to perform the following operation **at most `V` times**:

* Choose **2 different items**.
* Pay for the **the choosen one and get a free one if the free item cost is <= min(a, b), while A, B are the buyed items**.
* Get the **cheapest item for free**.
* In other words, if the three selected item prices are `a <= b <= c`, you pay `b + c` and get `a` for free.

Every item must either be **paid for or obtained for free**.

Return the **minimum total amount of money** required to obtain all the items.

### Constraints

* `1 <= N <= 10^5`
* `0 <= V <= 10^5`
* `1 <= cost[i] <= 10^9`
* `V <= N / 3`

### Example 1

```text
Input:
cost = [2, 3, 4, 1, 5, 6]
V = 2

Output:
16
```

**Explanation:**

We can group the items as:

```text
[1, 2, 3] -> 1 is free, pay 2 + 3
[4, 5, 6] -> 4 is free, pay 5 + 6
```

Total amount paid:

```text
2 + 3 + 5 + 6 = 16
```

---

### Example 2

```text
Input:
cost = [1, 2, 3, 4, 5, 6, 7]
V = 2

Output:
25
```

---

### Example 3

```text
Input:
cost = [2, 5, 3, 10, 4]
V = 1

Output:
17
```

---

### Example 4

```text
Input:
cost = [5, 5, 5, 5, 5, 5]
V = 2

Output:
20
```

---

### Example 5

```text
Input:
cost = [1, 2, 3, 4]
V = 1

Output:
9
```

### Function Signature

```cpp
long long minimumCost(vector<int>& cost, int V);
```

