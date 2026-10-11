## Maximum Product of Strictly Increasing Absolute Segments

You are given an integer array `nums`.

Divide `nums` into contiguous segments from left to right. A segment continues only while `abs(nums[i]) > abs(nums[i - 1])`. Whenever this condition fails, a new segment starts at `nums[i]`.

Compute the product of each segment and return the maximum product among all segments.

**Example 1:**

**Input:** `nums = [2,-3,4,-5,1,2]`

**Output:** `120`

**Explanation:**

* The segments are `[2,-3,4,-5]` (absolute values `2 < 3 < 4 < 5`) and `[1,2]`.
* Their products are `2 * -3 * 4 * -5 = 120` and `1 * 2 = 2`.
* The maximum is `120`.

**Example 2:**

**Input:** `nums = [3,2,1]`

**Output:** `3`

**Explanation:**

* The absolute values are decreasing, so every element is its own segment: `[3]`, `[2]`, `[1]`.
* The products are `3, 2, 1`, and the maximum is `3`.

**Example 3:**

**Input:** `nums = [-1,-2,-3,0,2]`

**Output:** `0`

**Explanation:**

* The segments are `[-1,-2,-3]` and `[0,2]`, because `abs(0) > abs(-3)` fails and `abs(2) > abs(0)` holds.
* Their products are `-6` and `0`, so the maximum is `0`.

**Constraints:**

* `1 <= nums.length <= 10^5`
* `-10 <= nums[i] <= 10`
* Every segment product fits in a 64-bit signed integer.