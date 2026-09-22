#include <bits/stdc++.h>
using namespace std;

long long repairPairs(vector<int>& A, vector<int> B, int K) {
    int N = A.size();

    long long mismatch = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            mismatch++;
        }
    }

    if(mismatch == 0) return 1LL * N;

    // Each operation can repair at most 2 mismatches
    long long repaired = min(mismatch, 2LL * K);

    // Already matching + newly repaired
    return (N - mismatch) + repaired;
}

int main() {
    vector<int> A1 = {0, 0, 0, 1, 1, 1};
    vector<int> B1 = {1, 1, 1, 0, 0, 0};

    cout << repairPairs(A1, B1, 2) << endl;
    // 4

    return 0;
}