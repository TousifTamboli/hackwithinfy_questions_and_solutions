#include <bits/stdc++.h>
using namespace std;

int solve(int d, vector<int>& nums) {
    if (nums.empty()) return 0;

    // 1. Sort and remove duplicates in O(N log N) time and O(1) space
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int ans = 0;
    int current_len = 1;

    // 2. Iterate through the unique times to find contiguous blocks
    for (int i = 1; i < nums.size(); i++) {
        // If the current number is consecutive to the previous one
        if (nums[i] == nums[i - 1] + 1) {
            current_len++;
        } 
        // If there is a gap, the block ends
        else {
            // Add the max tasks we can do in the completed block
            ans += current_len - (current_len / (d + 1));
            
            // Reset the length for the new block
            current_len = 1; 
        }
    }
    
    // Add the calculation for the final block
    ans += current_len - (current_len / (d + 1));

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
        {2, {1, 2, 3, 4, 5, 6, 7}}
    };

    for (int i = 0; i < testCases.size(); i++) {
        int D = testCases[i].first;
        vector<int> arr = testCases[i].second;

        cout << "Test Case " << i + 1 << ": " << solve(D, arr) << '\n';
    }

    return 0;
}