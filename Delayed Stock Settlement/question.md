## Delayed Stock Settlement

You are given an array `prices` of length `N`, where `prices[i]` is the price of a stock on day `i` (0-indexed).

You may make **at most one** buy-sell transaction: buy on day `i` and sell on day `j`. A stock bought on day `i` has a settlement delay of `(prices[i] % 10) + 1` days, so you can sell on day `j` only if `j >= i + (prices[i] % 10) + 1`.

Return the maximum profit `prices[j] - prices[i]` over all valid pairs `(i, j)`, or `0` if no positive profit is possible.

**Example 1:**

**Input:** `prices = [10,12,15,11,18]`

**Output:** `8`

**Explanation:**

* Buying on day `0` at price `10` has a delay of `10 % 10 + 1 = 1` day, so we can sell from day `1`.
* Selling on day `4` at `18` gives a profit of `8`.
* Buying at `12` (delay 3) allows selling only on day `4` for a profit of `6`, which is smaller.

**Example 2:**

**Input:** `prices = [7,2,9,3,1,15]`

**Output:** `13`

**Explanation:**

* Buying on day `1` at price `2` has a delay of `3` days, so we can sell from day `4`.
* Selling on day `5` at `15` gives a profit of `13`.

**Example 3:**

**Input:** `prices = [3,8,5,9,1]`

**Output:** `0`

**Explanation:**

* Buying at `3` on day `0` has a delay of `4` days, so the only sell day is `4` at price `1`, which is a loss.
* Buying at `8`, `5` or `9` has a delay of `9`, `6` or `10` days, so there is no valid sell day.
* No profitable transaction exists, so the answer is `0`.

**Constraints:**

* `1 <= N <= 10^5`
* `1 <= prices[i] <= 10^9`