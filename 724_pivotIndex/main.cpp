#include <iostream>

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int      sumLeft  = 0;
        int      sumRight = accumulate(nums.begin(), nums.end(), 0);
        for (int i        = 0; i < nums.size(); ++i) {
            sumRight -= nums[i];
            if (sumLeft == sumRight) {
                return i;
            }
            sumLeft += nums[i];
        }
        return -1;

    }
};

int main() {
    auto *solution = new Solution;
    vector<int> temp   = {3, 6, 8, 90, 234, 444, 555, 666, 678,};
    auto        result = solution->pivotIndex(temp);
    std::cout << "result : " << result << std::endl;
    return 0;
}
