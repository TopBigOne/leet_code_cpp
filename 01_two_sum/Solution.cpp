//
// Created by dev on 2024/7/15.
//

#include "Solution.h"
#include <map>

vector<int> Solution::twoSum(vector<int> &nums, int target) {
    map<int, int> map;
    vector<int>   result(2, -1);
    for (int      index = 0; index < nums.size(); index++) {
        int currValue  = nums[index];
        if (map.count(target - currValue) > 0 && map[target - currValue] != index) {
            result[0] = index;
            result[1] = map[target - currValue];
            break;
        }
        // 反过来存
        map[currValue] = index;
    }
    return result;
}
