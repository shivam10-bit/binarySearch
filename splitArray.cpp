class Solution {
public:
    // Helper function: returns number of subarrays required if max subarray sum <= mid
    int countSubarrays(vector<int>& a, int mid) {
        int n = a.size();
        int subarrays = 1;  // start with one subarray
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] <= mid) {
                sum += a[i];
            } else {
                subarrays++;
                sum = a[i];
            }
        }
        return subarrays;
    }

    // Main LeetCode function
    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end());
        int high = accumulate(a.begin(), a.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int subarrays = countSubarrays(a, mid);

            if (subarrays <= k) {
                ans = mid;        // possible answer
                high = mid - 1;   // try smaller
            } else {
                low = mid + 1;    // need larger sum
            }
        }
        return ans;
    }
};
