#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[1001][1001][2];

ll rec(const vector<int>& A, const vector<int>& B, const vector<vector<ll>>& cost, int i, int j, int last) {
    int m = A.size();
    int n = B.size();

    if(last != -1)
        if(dp[i][j][last] != -1) return dp[i][j][last];

    if(i == m && j < n) {
        int prev;
        if(last == 0) {
            prev = A[i-1];
        } else {
            prev = B[j-1];
        }

        long long rem = 0;
        int temp_j = j; 
        while(temp_j < n) {
            rem += cost[prev - 1][B[temp_j] - 1];
            prev = B[temp_j];
            temp_j++;
        }

        return dp[i][j][last] = rem; 
    } 
    
    if(j == n && i < m) {
        int prev;
        if(last == 0) {
            prev = A[i-1];
        } else {
            prev = B[j-1];
        }

        long long rem = 0;
        int temp_i = i; 
        while(temp_i < m) {
            rem += cost[prev - 1][A[temp_i] - 1];
            prev = A[temp_i];
            temp_i++;
        }

        return dp[i][j][last] = rem;
    }

    if(i == m && j == n) return 0;

    long long ans = 0;

    if(i == 0 && j == 0) {
        //take i
        long long take_i = rec(A, B, cost, i+1, j, 0);
        //take j
        long long take_j = rec(A, B, cost, i, j+1, 1);

        ans += min(take_i, take_j);
    } else {
        int prev;
        if(last == 0) {
            prev = A[i-1];
        } else {
            prev = B[j-1];
        }

        //take i
        long long curr = 0;
        curr = cost[prev - 1][A[i] - 1];
        long long take_i = curr + rec(A, B, cost, i+1, j, 0);

        //take j
        curr = cost[prev - 1][B[j] - 1];
        long long take_j = curr + rec(A, B, cost, i, j+1, 1);

        ans += min(take_i, take_j);


    }

    if (last == -1)
        return ans;

    return dp[i][j][last] = ans;
}

ll solve(const vector<int>& A, const vector<int>& B, const vector<vector<ll>>& cost) {
    int i = 0;
    int j = 0;
    int last = -1;
    int m = A.size();
    int n = B.size();
    memset(dp, -1, sizeof(dp));
    
    return rec(A, B, cost, i, j, last);
}

int main() {
    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5, 6};

    long long INF = 1000000000;
    vector<vector<ll>> cost = {
        {INF, 10,  INF, INF,   INF, INF},
        {INF, INF, 10,  50000, INF, INF},
        {INF, INF, INF, INF,   INF, 10},
        {INF, INF, INF, INF,   10,  INF},
        {INF, INF, 50000, INF, INF, 10},
        {INF, INF, INF, INF,   INF, INF}
    };

    cout << solve(A, B, cost) << '\n';

    return 0;
}