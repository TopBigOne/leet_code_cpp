#include <iostream>

class Solution {
public:
    /**
     * 核心代码，carry >7,carry<-8
     * @param x
     * @return
     */
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int carry = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && carry > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && carry < -8)) {
                return 0;
            }
            res = res * 10 + carry;
            x /= 10;
        }
        return res;

    }


    int reverse2(int x) {
        int res = 0;
        while (x != 0) {
            int carry = x % 10;
            x /= 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && carry > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && carry < -8)) {
                return 0;
            }
            res = res * 10 + carry;

        }
        return res;
    }

    int reverse3(int x) {
        int res = 0;
        while (x != 0) {
            int carry = x % 10;

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && carry > 7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && carry < -8)) {
                return 0;
            }
            res = res * 10 + carry;
            x /= 10;
        }
        return res;

    }
};

int main() {

    return 0;
}
