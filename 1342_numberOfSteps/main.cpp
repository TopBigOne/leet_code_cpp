#include <iostream>

using namespace std;

class Solution {

public:
    int numberOfSteps(int num) {
        // step 1  : 位运算判断奇偶
        int count = 0;
        while (num != 0) {
            // step 2-1: 偶数则 右移一位
            if ((num & 1) == 0) {
                num >>= 1;
            } else {
                // step 2-2: 奇数则 减 1
                num -= 1;
            }
            // step 3: 计数
            count++;
        }
        return count;
    }
};

int main() {
    auto s = new Solution;

    // case 1:
    int num    = 14;
    int result = s->numberOfSteps(num);
    cout << " " << num << " : " << result << endl;

    // case 2:
    num    = 8;
    result = s->numberOfSteps(num);
    cout << " " << num << " : " << result << endl;

    delete s;

    return 0;
}
