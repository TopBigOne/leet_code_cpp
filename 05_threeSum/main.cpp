#include <iostream>
#include <vector>
#include "leet_code_utils.h"

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int size = nums.size();

        for (int i = 0; i < size - 2; i++) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    // sum  = 0;
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }

            }
        }
        return ans;
    }

    /**
     *
     * @param nums   引用类型
     * @return
     */
    vector<vector<int>> threeSum2(vector<int> &nums) {
        vector<vector<int>> ans;
        size_t              size = nums.size();

        if (size < 3) {
            return ans;
        }
        // do a sort.
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left  = i + 1;
            int right = static_cast<int>(size - 1);

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // case 1:
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                    continue;

                }
                // case 2:
                if (sum < 0) {
                    left++;
                    continue;

                }
                // case 3:
                if (sum > 0) {
                    right--;
                    continue;

                }
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum3(vector<int> &nums) {
        vector<vector<int>> ans;
        size_t              size = nums.size();
        if (size < 3) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left  = i + 1;
            int right = static_cast<int > (size - 1);
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // case 1:
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                    continue;
                }
                // case 2:
                if (sum < 0) {
                    left++;
                    continue;
                }
                // case 3:
                if (sum > 0) {
                    right--;
                    continue;
                }
            }
        }

        return ans;
    }
};

/**
 * https://leetcode.cn/problems/3sum/submissions/
 * @return
 */
int main() {
    vector<int>         nums = {-1, 0, 1, 2, -1, -4};
    Solution            solution;
    vector<vector<int>> ans  = solution.threeSum3(nums);
    print_v2(ans);
    return 0;
}
