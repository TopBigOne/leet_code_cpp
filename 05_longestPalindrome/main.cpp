#include <iostream>
#include "Solution.h"

#include <vector>

using namespace std;

//最长回文子串 : https://leetcode.cn/problems/longest-palindromic-substring/
class Solution1 {
public:
    string longestPalindrome(string s) {
        size_t len = s.size();
        if (len == 0 || len == 1) {
            return s;
        }
        vector<int> max(2, 0);

        for (int i = 0; i < len; i++) {
            vector<int> old = centerSpread(s, i, i);
           // printVector("old", old);
            vector<int> even = centerSpread(s, i, i + 1);
            printVector("even", even);
            // cout << "============" << endl;
            vector<int> temp = even.at(1) > old.at(1) ? even : old;
            if (temp.at(1) > max.at(1)) {
                max = temp;
            }
        }
        // C++ 和java的substr 不一样！
        return s.substr(max.at(0), max.at(1));
    }

private:
    vector<int> centerSpread(string s, int i, int j) {
        vector<int> result(2, 0);
        size_t      len = s.size();
        while (i >= 0 && j < len) {
            if (s.at(i) == s.at(j)) {
                i--;
                j++;
                continue;
            }
            break;
        }
        // cout << " i : " << i << " , j : " << j << endl;
        return vector<int>{i + 1, j - i - 1};
    }

    void printVector(string type, vector<int> indexContent) {
        cout << type << ":";
        for (const auto &item: indexContent) {
            cout << item << " ";
        }
        cout << endl;
    }
};

void test1();

void test2();

int main() {

    test1();
    test2();

    return 0;
}


void test1() {
    puts("test1: ");
    Solution1 solution;
    string    s = "babad";
    s = "cbbd";
    string result = solution.longestPalindrome(s);
    cout << "result : " << result << endl;
}


void test2() {
    Solution solution;
    string   s = "babad";
    s = "cbbd";
    string result = solution.longestPalindrome(s);
    cout << "result : " << result << endl;


}
