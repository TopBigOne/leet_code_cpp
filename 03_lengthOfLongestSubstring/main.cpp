#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

#include <vector>

/**
 * 无重复字符的最长子串 ：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 * 输入: s = "abc abc bb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。


 * @return
 */

class Solution {
public:
    /**
     * 滑动窗口
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(string s) {
        int    maxLength = 0;
        size_t len;
        // base corner
        if ((len = s.length()) == 0) {
            return maxLength;
        }
        int         left  = 0;
        int         right = 0;
        vector<int> window(256);

        while (right < len) {
            char rightChar = s.at(right);
            window[rightChar]++;
            while (window[rightChar] > 1) {
                char leftChar = s.at(left);
                window[leftChar]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }

    int lengthOfLongestSubstring2(string s) {
        int    left      = 0;
        int    right     = 0;
        int    maxLength = 0;
        size_t len;
        if ((len = s.length()) == 0) {
            return maxLength;
        }
        vector<int> window(256);
        while (right < len) {
            char rightChar = s.at(right);
            window[rightChar]++;
            while (window[rightChar] > 1) {
                char leftChar = s.at(left);
                window[leftChar]--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};

int main() {
    string s = "abcabcab";
    s = " ";
    Solution solution;
    int      result = solution.lengthOfLongestSubstring(s);
    cout << "result:" << result << endl;

    return 0;
}
