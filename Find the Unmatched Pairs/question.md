## Question — Repair Pairs

You are given two binary arrays `A`, `B` of `N` size and `K`.

You want to see all the pairs for all i such that `1 <= i <= N`.

* The mismatch pair is when `A[i] = 0 and B[i] = 1` or `A[i] = 1 and B[i] = 0`
* Your task is to see all pairs `(A[i], B[i]), (A[i+1], B[i+1])... (A[N-1], B[N-1])` and try to repair them with atmost K oprations such that `A[i] = B[i]`.
* In one operation you can change any two elements and change them to either 1 or 0

Return the **Maximum number of repaired items you can get after using atmost K items**.

### Constraints

* `1 <= N <= 10^5`
* `0 <= A[i],B[i] <= 1`
* `1 <= K <= 10^5`

### Example 1

```text
Input:
A = [0, 0, 0, 1, 1, 1]
B = [1, 1, 1, 0, 0, 0]
K = 2

Output:
4
```

**Explanation:**

We can group the items as:

```text
There are total 6 mismatch pairs, use K = 2 and repair the pairs to get total 4 repaired pairs at end.
```

Total amount paid:

---

### Example 2

```text
Input:
A = [0, 1, 0, 1]
B = [1, 0, 1, 0]
K = 5

Output:
4
```

---

### Example 3

```text
Input:
A = [1, 1, 1, 1, 1, 1, 1, 1]
B = [1, 1, 1, 1, 1, 1, 1, 1]
K = 1

Output:
8
```

### Function Signature

```cpp
long long repairPairs(vector<int>& A, vector<int>B, int K);
```

