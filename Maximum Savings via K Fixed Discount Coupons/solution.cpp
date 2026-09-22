#include <bits/stdc++.h>
using namespace std;

int solve(int n, int w, int k, int d, vector<int>& p) {
    multiset<int> top;
    multiset<int> rem;
    int maxi = INT_MIN;

    auto add = [&](int x) {
        if((int)top.size() < k) {
            top.insert(x);
        } else if(*top.begin() < x) {
            rem.insert(*top.begin());
            top.erase(*top.begin());
            top.insert(x);
        } else {
            rem.insert(x);
        }
    };

    auto remove = [&](int x) {
        auto it = top.find(x);

        if(it != top.end()) {
            top.erase(it);

            if(!rem.empty()) {
                auto toput = prev(rem.end());
                top.insert(*toput);
                rem.erase(toput);
            }
        } else {
            it = rem.find(x);
            if(it != rem.end()) {
                rem.erase(it);
            }
        }
    };

    auto getopk = [&]() {
        int sum = 0;
        for(auto it = top.begin(); it != top.end(); ++it) {
            int dis = min(d, *it);
            sum += dis;
        }
        return sum;
    };

    for(int i=0; i<w; i++) {
        add(p[i]);
    }

    int curr = getopk();
    maxi = max(maxi, curr);


    for(int i=w; i<n; i++) {
        remove(p[i-w]);
        add(p[i]);

        int curr = getopk();
        maxi = max(maxi, curr);
        
    }

    return maxi;


}

int main() {
    int n, w, k, d;

    cin >> n >> w >> k >> d;

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << solve(n, w, k, d, p) << '\n';

    return 0;
}