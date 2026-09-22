#include <bits/stdc++.h>
using namespace std;

int solve(int T, int capacity, vector<vector<int>>& trips) {
    // Maximum coordinate is 1000 according to constraints
    vector<int> diff(1002, 0);

    int maxPos = 0;

    // Build difference array
    for (int i = 0; i < T; i++) {
        int passengers = trips[i][0];
        int from = trips[i][1];
        int to = trips[i][2];

        diff[from] += passengers;
        diff[to] -= passengers;

        maxPos = max(maxPos, to);
    }

    long long answer = 0;
    int passengersOnBus = 0;

    // Process each segment [x, x+1]
    for (int x = 0; x < maxPos; x++) {
        passengersOnBus += diff[x];

        int standing = max(0, passengersOnBus - capacity);

        // Segment length is 1
        answer += standing;
    }

    return (int)answer;
}

int main() {
    // Example 1
    {
        int T = 2;
        int capacity = 4;

        vector<vector<int>> trips = {
            {3, 1, 5},
            {2, 3, 7}
        };

        cout << solve(T, capacity, trips) << endl;
        // Output: 2
    }

    // Example 2
    {
        int T = 3;
        int capacity = 5;

        vector<vector<int>> trips = {
            {2, 0, 3},
            {1, 1, 4},
            {2, 3, 5}
        };

        cout << solve(T, capacity, trips) << endl;
        // Output: 0
    }

    // Example 3
    {
        int T = 3;
        int capacity = 3;

        vector<vector<int>> trips = {
            {2, 1, 4},
            {2, 2, 5},
            {1, 3, 6}
        };

        cout << solve(T, capacity, trips) << endl;
        // Output: 3
    }

    // Example 4
    {
        int T = 4;
        int capacity = 6;

        vector<vector<int>> trips = {
            {5, 0, 3},
            {4, 1, 5},
            {2, 2, 4},
            {3, 4, 6}
        };

        cout << solve(T, capacity, trips) << endl;
        // Output: 9
    }

    return 0;
}