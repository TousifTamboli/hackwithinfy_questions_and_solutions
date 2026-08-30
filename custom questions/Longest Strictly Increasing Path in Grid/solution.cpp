#include<bits/stdc++.h>
using namespace std;

int recursion(vector<vector<int>>& nums, int i, int j, int dash, vector<vector<vector<int>>>& dp) {
    int m = nums.size();
    int n = nums[0].size();

    if(i >= m || j >= n || i < 0 || j < 0) return 0;

    if(dp[i][j][dash] != -1) return dp[i][j][dash];

    int dash1 = 0;
    int dash2 = 0;
    int dash3 = 0;
    int dash4 = 0;

    if(dash != 1) {

         if (i-2 >= 0 && nums[i-2][j] > nums[i][j])
            dash1 = 1 + recursion(nums, i-2, j, 1, dp);

        if (i+2 < m && nums[i+2][j] > nums[i][j])
            dash2 = 1 + recursion(nums, i+2, j, 1, dp);

        if (j-2 >= 0 && nums[i][j-2] > nums[i][j])
            dash3 = 1 + recursion(nums, i, j-2, 1, dp);

        if (j+2 < n && nums[i][j+2] > nums[i][j])
            dash4 = 1 + recursion(nums, i, j+2, 1, dp);
        
    }

    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
    

    if (i > 0 && nums[i-1][j] > nums[i][j])
        up = 1 + recursion(nums, i-1, j, dash, dp);

    if (i+1 < m && nums[i+1][j] > nums[i][j])
        down = 1 + recursion(nums, i+1, j, dash, dp);

    if (j > 0 && nums[i][j-1] > nums[i][j])
        left = 1 + recursion(nums, i, j-1, dash, dp);

    if (j+1 < n && nums[i][j+1] > nums[i][j])
        right = 1 + recursion(nums, i, j+1, dash, dp);

    return dp[i][j][dash] = max({
        1,
        dash1,
        dash2,
        dash3,
        dash4,
        up,
        down,
        left,
        right
    });
}

int solve(int& m, int& n, vector<vector<int>>& nums) {
    int ans = 0;

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, recursion(nums, i, j, 0, dp));
        }
    }

    return ans;
}

int main() {

    vector<vector<int>> nums = {
        {1, 2},
        {3, 4}
    };

    int m = nums.size();
    int n = nums[0].size();

    cout << solve(m, n, nums) << endl;

    return 0;
}