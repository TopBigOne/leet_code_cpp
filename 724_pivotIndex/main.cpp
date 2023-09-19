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
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
