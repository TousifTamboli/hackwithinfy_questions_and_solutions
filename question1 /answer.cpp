#include <bits/stdc++.h>
using namespace std;

// Input Format
// The first line contains an integer N, denoting the number of tasks.
// The second line contains an integer M, denoting the number of servers.
// The third line contains an integer W, denoting the thermal penalty parameter.
// The fourth line contains N space-separated integers denoting the base duration of the i-th task.

// Constraints
// 1 ≤ N ≤ 10^5
// 1 ≤ M ≤ 10^2
// 0 ≤ W ≤ 10^3
// 1 ≤ tasks[i] ≤ 10^4


long long ans() {
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    vector<int> preva(M, 0);

    for (int i = 0; i < M; i++) {
        pq.push({0, i});
    }

    stable_sort(tasks.begin(), tasks.end(), greater<int>());

    for (int i = 0; i < N; i++) {
        long long value = pq.top().first;
        int index = pq.top().second;
        pq.pop();

        long long curr = (long long)tasks[i] + 1LL * preva[index] * W;

        pq.push({value + curr, index});
        preva[index]++;
    }

    long long maxi = 0;

    while (!pq.empty()) {
        maxi = max(maxi, pq.top().first);
        pq.pop();
    }

    return maxi;
}