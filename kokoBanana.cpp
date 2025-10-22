#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        for (int x : piles) {
            if (x > maxi) maxi = x;
        }
        int low = 1;
        int high = maxi;
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFinish(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canFinish(const vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int x : piles) {
            // ceiling of x / speed
            hours += (x + speed - 1) / speed;
            if (hours > h) return false;  // early exit
        }
        return hours <= h;
    }
};
