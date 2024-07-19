#include <iostream>

/**
 * @author : dev
 * @version :
 * @Date :  1/25/21 11:41 PM
 * @Desc :   leetcode 53: 最大子序和 ：字节半年 27 次 ：https://leetcode-cn.com/problems/maximum-subarray/
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * <p>
 * 示例:
 * <p>
 * 输入: [-2,1,-3,4,-1,2,1,-5,4]
 * 输出: 6
 * 解释:连续子数组 [4,-1,2,1] 的和最大，为 6。
 * <p>
 * 可以用贪心算法和 dp；
 * 贪心：若当前指针元素之前的和 小于 0 ，则丢弃当前元素之前的数列；
 * <p>
 * <p>
 */

#include <vector>
#include <iostream>
#include "leet_code_utils.h"

using namespace std;

class Solution {
public:
    /**
     * 累加的方式
     * @param nums
     * @return
     */
    int maxSubArray(vector<int> &nums) {
        size_t      size   = nums.size();
        int         result = nums[0];
        int         sum    = nums[0];
        for (size_t i      = 1; i < size; i++) {
            sum = max(nums[i], nums[i] + sum);
            if (sum > result) {
                result = sum;
            }
        }


        return result;
    }

    /**
     * 练习累加
     * @param nums
     * @return
     */
    int maxSubArray2(vector<int> &nums) {
        int      result  = nums[0];
        int      max_sum = nums[0];
        for (int i       = 1; i < nums.size(); i++) {
            max_sum = max(nums[i] + max_sum, nums[i]);
            if (max_sum > result) {
                result = max_sum;
            }
        }
        return result;
    }

    /**
     * 动态规划
     * @param nums
     * @return
     */
    int maxSubArray3(vector<int> &nums) {
        int         len    = nums.size();
        vector<int> dp(len, 0);
        int         result = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];
            result = max(result, dp[i]);
        }
        return result;
    }

    int maxSubArray4(vector<int> &nums) {
        size_t      len    = nums.size();
        vector<int> dp(len, 0);
        int         result = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            //max(dp[i - 1] , 0)
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            if (result < dp[i]) {
                result = dp[i];
            }
        }
        return result;
    }

    int maxSubArray5(vector<int> &nums) {
        size_t      size = nums.size();
        vector<int> dp(size);
        int         ans  = nums[0];
        dp[0] = nums[0];
        for (int i = 1; i < size; i++) {
            dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + nums[i];
            ans = max(dp[i],ans);
        }
        return ans;


    }

};

int main() {
    vector<int> nums   = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution    solution;
    int         maxSum = solution.maxSubArray5(nums);
    cout << "max sum : " << maxSum << endl;

    return 0;
}
