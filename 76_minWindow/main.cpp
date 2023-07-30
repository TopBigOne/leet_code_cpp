#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        size_t sLength = s.length();
        size_t tLength = t.length();

        vector<int> window(128, 0);// 256
        vector<int> need(128, 0);

        int minLength = static_cast<int >(sLength + 1);

        int       count = 0;
        int       start = 0;
        int       end   = 0;
        string    res;
        for (char c: t) {
            need[c]++;
        }

        while (end < sLength) {
            char currChar = s.at(end);
            window[currChar]++;
            // 条件符合
            if (need[currChar] > 0 && window[currChar] <= need[currChar]) {
                count++;
            }
            while (count == tLength) {
                char startChar = s.at(start);
                if (need[startChar] > 0 && window[startChar] <= need[startChar]) {
                    count--;
                }
                int temp = end - start + 1;
                if (temp < minLength) {
                    minLength = temp;
                    cout << "temp : " << temp << endl;
                    res = s.substr(start, minLength);
                }
                start++;
                window[startChar]--;
            }

            end++;

        }
        return res;

    }

    /**
     * https://leetcode.cn/problems/minimum-window-substring/solutions/258016/c-zuo-you-zhi-zhen-fa-xiang-jie-by-yizhe-shi/
     * @param s
     * @param t
     * @return
     */
    string minWindow2(string s, string t) {

        unordered_map<char, int> count;
        for (auto                c: t) {
            count[c]++;
        }

        int    len    = 0;
        int    n      = s.size();
        int    minlen = n;
        string ans    = "";
        int    l      = 0, r = 0;
        for (; r < n; r++) {
            count[s[r]]--;
            if (count[s[r]] >= 0) len++;
            while (len == t.size()) {
                if (r - l + 1 <= minlen) {
                    minlen = r - l + 1;
                    ans    = s.substr(l, r - l + 1);
                }
                count[s[l]]++;
                if (count[s[l]] > 0) {
                    len--;
                }
                l++;
            }
        }
        return ans;

    }

    /**
     *
     * @param s : ADOBECODEBANC
     * @param t  :ABC
     * @return
     */
    string minWindow3(string s, string t) {
        size_t      sLength   = s.length();
        size_t      tLength   = t.length();
        vector<int> window(128, 0);
        vector<int> need(128, 0);
        int         minLength = sLength + 1;
        int         count     = 0;
        int         start     = 0;
        int         end       = 0;
        string      res;
        // 记录t中每个字符出现的字数
        for (char   c: t) {
            need[c]++;
        }
        while (end < sLength) {
            char currChar = s.at(end);
            window[currChar]++;
            if (need[currChar] > 0 && window[currChar] <= need[currChar]) {
                count++;
            }
            while (count == tLength) {
                char startChar = s.at(start);
                if (need[startChar] > 0 && window[startChar] <= need[startChar]) {
                    count--;
                }
                int temp = end - start + 1;
                if (temp < minLength) {
                    minLength = temp;
                    res       = s.substr(start, minLength);
                }
                start++;
                window[startChar]--;
            }

            end++;
        }
        return res;
    }

};


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    // BANC

    Solution solution;
    string   res1 = solution.minWindow(s, t);
    string   res2 = solution.minWindow2(s, t);
    string   res3 = solution.minWindow3(s, t);
    cout << "result 1 : " << res1 << endl;
    cout << "result 2 : " << res2 << endl;
    cout << "result 3 : " << res3 << endl;
    return 0;
}
