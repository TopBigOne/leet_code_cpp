#include <iostream>

/**
 * 258. 各位相加:https://leetcode.cn/problems/add-digits/description/
 * n=100a+10b+c= 99a+9b+a+b+c, 所以n%9=a+b+c (a+b+c<=8)
 * 记住一点即可：abc % 9 = (a+b+c) % 9
*
 */
class Solution {
public:
    int addDigits(int num) {
        if (num > 9) {
            num %= 9;
            if (num == 0) {
                return 9;
            }
        }
        return num;
    }
};

int main() {
    Solution solution;
    int      result = solution.addDigits(999);
    std::cout << "result:" << result << std::endl;

    return 0;
}
