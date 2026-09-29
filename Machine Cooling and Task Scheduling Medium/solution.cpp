#include <bits/stdc++.h>
using namespace std;

int solve(int d, vector<int>& nums) {
    if (nums.empty()) return 0;

    // 1. Put all tasks into an unordered_set to handle duplicates 
    // and allow lightning-fast O(1) lookups.
    unordered_set<int> task_set(nums.begin(), nums.end());

    // 2. Find the starting and ending times
    int min_time = *min_element(nums.begin(), nums.end());
    int max_time = *max_element(nums.begin(), nums.end());

    int ans = 0;
    int consecutive = 0;

    // 3. Traverse second-by-second from the first task to the last task
    for (int i = min_time; i <= max_time; i++) {
        
        if (consecutive == d) {
            // CASE 1: Machine is overheated. 
            // Forced cooldown. It skips whatever is at time 'i'.
            consecutive = 0;
        } 
        else if (task_set.count(i)) {
            // CASE 2: Machine is fine AND a task exists at time 'i'.
            // Do the task.
            ans++;
            consecutive++;
        } 
        else {
            // CASE 3: Machine is fine BUT no task exists at time 'i'.
            // Natural cooldown.
            consecutive = 0;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, vector<int>>> testCases = {
        {2, {1, 2, 3, 4}},
        {2, {1, 1, 2, 3, 5, 6, 6, 7, 8, 9}},
        {1, {5, 3, 4, 10}},
        {3, {1, 3, 5, 7}},
        {2, {1, 2, 3, 4, 5, 6, 7}},
        {3, {1, 2, 3, 4, 5, 6, 8, 9, 10}} // Your dry run test case
    };

    for (int i = 0; i < testCases.size(); i++) {
        int D = testCases[i].first;
        vector<int> arr = testCases[i].second;

        cout << "Test Case " << i + 1 << ": " << solve(D, arr) << '\n';
    }

    return 0;
}