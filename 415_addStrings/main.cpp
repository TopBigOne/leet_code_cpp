#include <iostream>
#include <string>

using namespace std;

/**
 * 415:字符串相加： https://leetcode.cn/submissions/detail/447666657/
 *
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int    m     = static_cast<int >(num1.length() - 1);
        int    n     = static_cast<int >(num2.length() - 1);
        string sb;
        int    carry = 0;
        while (m >= 0 || n >= 0) {
            int x   = m < 0 ? 0 : num1.at(m--) - '0';
            int y   = n < 0 ? 0 : num2.at(n--) - '0';
            int sum = x + y + carry;
            carry = sum / 10;
            // std::string.to_string();
            sb.append(to_string(sum % 10));
        }
        if (carry > 0) {
            sb.append(to_string(carry));
        }
        // 反转
        reverse(sb.begin(), sb.end());
        return sb;
    }

    string addStrings2(string num1, string num2) {
        int    m     = static_cast<int >(num1.length() - 1);
        int    n     = static_cast<int >(num2.length() - 1);
        string sb;
        int    carry = 0;
        while (m >= 0 || n >= 0) {
            int x   = m < 0 ? 0 : num1.at(m--) - '0';
            int y   = n < 0 ? 0 : num2.at(n--) - '0';
            int sum = x + y + carry;
            // 进位
            carry = sum / 10;
            sb.append(to_string(sum % 10));

        }
        if (carry > 0) {
            sb.append(to_string(carry));
        }
        reverse(sb.begin(), sb.end());
        return sb;
    }

    string addStrings3(string num1, string num2) {
        int    m     = static_cast<int >(num1.length() - 1);
        int    n     = static_cast<int >(num2.length() - 1);
        string sb;
        int    carry = 0;
        while (m >= 0 || n >= 0) {
            int x   = m < 0 ? 0 : num1.at(m--) - '0';
            int y   = n < 0 ? 0 : num2.at(n--) - '0';
            int sum = x + y + carry;
            carry = sum / 10;
            sb.append(to_string(sum % 10));
        }
        if (carry > 0) {
            sb.append(to_string(carry));
        }
        reverse(sb.begin(), sb.end());
        return sb;
    }


};

int main() {

    string   num1   = "11";
    string   num2   = "123";
    Solution solution;
    string   result = solution.addStrings3(num1, num2);
    cout << "result :" << result << endl;

    return 0;
}
