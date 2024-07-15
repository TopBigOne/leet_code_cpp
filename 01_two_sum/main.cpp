#include <iostream>
#include <map>
#include <vector>

#include "Solution.h"

using namespace std;

#include <memory>

/**
 * 两数之和
 * https://leetcode.cn/problems/two-sum/solutions/4361/liang-shu-zhi-he-by-gpe3dbjds1/
 * @return
 */

vector<int> twoSum(vector<int> &nums, int target);

void test1();

void test2();


int main() {

    test1();
    test2();

    return 0;


}


vector<int> twoSum(vector<int> &nums, int target) {
    map<int, int> map;
    vector<int>   result(2, -1);
    for (int      index = 0; index < nums.size(); index++) {
        int currValue  = nums[index];
        if (map.count(target - currValue) > 0 &&
            map[target - currValue] != index) {
            result[0] = index;
            result[1] = map[target - currValue];
            break;
        }
        // 存放当前值的index
        map[currValue] = index;
    }
    return result;
}


void test1() {
    vector<int>     nums{2, 11, 67, 32, 7};
    int             target = 9;
    vector<int>     result = twoSum(nums, target);
    for (const auto &item: result) {
        cout << "result:" << item << endl;
    }

}

void test2() {
    cout << __FUNCTION__ << endl;
    vector<int>               nums{2, 11, 67, 32, 7};
    std::unique_ptr<Solution> ptr    = std::unique_ptr<Solution>();
    vector<int>               result = ptr->twoSum(nums, 9);
    for (const auto           &item: result) {
        cout << "   result :" << item << endl;
    }

}









