#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        size_t n = nums1.size();
        size_t m = nums2.size();
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int leftMax1;
        int leftMax2;
        int rightMin1;
        int rightMin2;
        int c1   = 0;
        int c2   = 0;
        int low  = 0;
        int high = 2 * n;

        while (low <= high) {
            c1        = (low + high) >> 1;
            c2        = m + n - c1;
            leftMax1  = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
            rightMin1 = c1 == 2 * n ? INT_MAX : nums1[c1 / 2];

            leftMax2  = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
            rightMin2 = c2 == 2 * m ? INT_MAX : nums2[c2 / 2];
            if (leftMax1 > rightMin2) {
                high = c1 - 1;
            } else if (leftMax2 > rightMin1) {
                low = c1 + 1;
            } else {
                break;
            }
        }

        return (max(leftMax1, leftMax2) + min(rightMin1, rightMin2)) / 2.0;


    }

    double findMedianSortedArrays2(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if (n > m)  //保证数组1一定最短
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

        while (lo <= hi)   //二分
        {
            c1 = (lo + hi) / 2;  //c1是二分的结果
            c2 = m + n - c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

            if (LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;


    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
