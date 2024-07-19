#include <iostream>
#include <vector>

using namespace std;

/**
 * 88. 合并两个有序数组 :  https://leetcode.cn/problems/merge-sorted-array/
 */

class Solution {
public:

    void merge(vector<int> nums1, int m, vector<int> nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            nums1[k] = nums1[i] > nums2[j] ?nums1[i--] : nums2[j--];

            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }

    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {


    return 0;
}
