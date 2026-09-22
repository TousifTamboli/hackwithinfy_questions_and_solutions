#include <bits/stdc++.h>
using namespace std;

long long minimumCost(vector<int>& cost, int V) {
    int N = cost.size();

    // Sort prices
    sort(cost.begin(), cost.end());

    // Total cost if we buy everything
    long long total = 0;
    for (int x : cost) {
        total += x;
    }

    // Number of items that can actually be free
    int freeItems = min(V, N / 3);

    int start = N - 3 * freeItems;

    long long saved = 0;

    for (int i = start; i < N; i += 3) {
        saved += cost[i];
    }

    return total - saved;
}

int main() {

    // Example 1
    vector<int> cost1 = {1, 2, 3, 4, 5, 6};
    int V1 = 2;

    cout << minimumCost(cost1, V1) << endl;

    // Example 2
    vector<int> cost2 = {1, 2, 3, 4, 5, 6, 7};
    int V2 = 2;

    cout << minimumCost(cost2, V2) << endl;

    // Example 3
    vector<int> cost3 = {2, 5, 3, 10, 4};
    int V3 = 1;

    cout << minimumCost(cost3, V3) << endl;

    return 0;
}