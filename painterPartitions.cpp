#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int> &A = nums1, &B = nums2;
        int n1 = A.size(), n2 = B.size();
        // ensure A is the smaller array
        if (n1 > n2) {
            return findMedianSortedArrays(B, A);
        }

        int total = n1 + n2;
        int half = (total + 1) / 2;

        int low = 0, high = n1;
        while (low <= high) {
            int i = (low + high) / 2;
            int j = half - i;

            int Aleft   = (i == 0 ? numeric_limits<int>::min() : A[i-1]);
            int Aright  = (i == n1 ? numeric_limits<int>::max() : A[i]);
            int Bleft   = (j == 0 ? numeric_limits<int>::min() : B[j-1]);
            int Bright  = (j == n2 ? numeric_limits<int>::max() : B[j]);

            // correct partition found
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return (double) max(Aleft, Bleft);
                } else {
                    return ((double)max(Aleft, Bleft) + (double)min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                // we are too far right in A, move left
                high = i - 1;
            }
            else {
                // Aleft <= Bright but Bleft > Aright → move right in A
                low = i + 1;
            }
        }

        // Shouldn't reach here if inputs are valid
        throw invalid_argument("Input arrays are not valid for median finding");
    }
};
