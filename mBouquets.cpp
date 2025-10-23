#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(const vector<int> &bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int consec = 0;
        for (int b : bloomDay) {
            if (b <= days) {
                consec++;
                if (consec == k) {
                    bouquets++;
                    consec = 0;
                    if (bouquets >= m) return true;
                }
            } else {
                consec = 0;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if (need > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
