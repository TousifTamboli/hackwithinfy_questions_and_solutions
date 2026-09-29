**Machine Cooling and Task Scheduling**

A machine processes tasks, and each task takes exactly `1` unit of time. The machine can process at most `D` tasks **consecutively**. After processing `D` consecutive tasks, it overheats and must **cool down for exactly `1` unit of time** before it can process another task.

You are given an integer `D` and an integer array `arr`, where `arr[i]` is the arrival time of the `i-th` task. The following rules apply:

* A task can only be processed during the time slot equal to its arrival time.
* The machine can handle at most one task per time slot, so tasks with the same arrival time cannot all be completed.
* If the machine is idle during a time slot, it cools down and its consecutive task count resets to `0`.
* The machine is initially cool.
* Tasks may be skipped.

Return *the **maximum** number of tasks that can be completed.*

Example 1:

```
Input: D = 2, arr = [1,2,3,4]
Output: 3
Explanation: The machine works at times 1 and 2, cools down at time 3, and works at time 4.
A total of 3 tasks are completed.
```

Example 2:

```
Input: D = 2, arr = [1,1,2,3,5,6,6,7,8,9]
Output: 6
Explanation: The distinct time slots are 1, 2, 3, 5, 6, 7, 8, 9.
Slots 1-3: work at 1 and 2, cool down at 3 (2 tasks).
Slot 4 is idle, so the machine is cool again.
Slots 5-9: work at 5 and 6, cool down at 7, work at 8 and 9 (4 tasks).
A total of 6 tasks are completed.
```

Example 3:

```
Input: D = 1, arr = [5,3,4,10]
Output: 3
Explanation: Sorted, the time slots are 3, 4, 5, 10.
The machine works at 3, cools down at 4, and works at 5 (2 tasks).
It then works at 10 (1 task).
A total of 3 tasks are completed.
```

Example 4:

```
Input: D = 3, arr = [1,3,5,7]
Output: 4
Explanation: No two tasks arrive in consecutive time slots, so the machine never overheats.
```

Example 5:

```
Input: D = 2, arr = [1,2,3,4,5,6,7]
Output: 5
Explanation: Work at 1 and 2, cool at 3, work at 4 and 5, cool at 6, work at 7.
```

Constraints:

* `1 <= D <= 10^5`
* `1 <= arr.length <= 10^5`
* `1 <= arr[i] <= 10^9`

---