#include <iostream>
#include <vector>
#include <math.h>

using  namespace std;
class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        size_t  size = nums.size();
        vector<int> dp(size,1);
        int res = 0;
        for(size_t i= 0; i<size;i++){
            for (int j = 0; j < i; ++j) {
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            res = max(res,dp[i]);
        }
        return res;
    }
};
int main() {
    Solution solution;

    return 0;
}
