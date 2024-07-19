//
// Created by dev on 2023/7/30.
//

#include "Solution.h"


Solution::Solution() {
    puts("test2 :");
}

string Solution::longestPalindrome(string s) {
    int len = s.length();
    if (len < 2) {
        return s;
    }
    // index 0 ： 起始位置； index 1 : 长度
    vector<int> max(2, 0);

    for (int i = 0; i < len; ++i) {
        vector<int> odd  = centerSpread(s, i, i);
        vector<int> even = centerSpread(s, i, i + 1);
        //  比较长度
        vector<int> temp = odd.at(1) > even.at(1) ? odd : even;
        if (temp.at(1) > max.at(1)) {
            max = temp;
        }

    }
    return s.substr(max.at(0), max.at(1));


}

vector<int> Solution::centerSpread(string s, int i, int j) {
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
    return vector<int>{i + 1, j - i - 1};
}

/**
 * 最长回文子串
 * @param s
 * @return
 */
string Solution::longestPalindrome2(string s) {
    int len = s.length();
    if (len < 2) {
        return s;
    }
    vector<int> max(2, 0);
    for (int    i = 0; i < len; ++i) {
        vector<int> odd  = centerSpread2(s, i, i);
        vector<int> even = centerSpread2(s, i, i + 1);
        vector<int> temp = odd.at(1) > even.at(1) ? odd : even;
        if (temp.at(1) > max.at(1)) {
            max = temp;
        }
    }

    return s.substr(max.at(0), max.at(1));
}


vector<int> Solution::centerSpread2(string s, int i, int j) {
    // 数组大小是2，index 0 ： 起始位置，1： 长度；
    vector<int> result(2, 0);
    size_t      len = s.size();
    while (i >= 0 && j < len) {
        if (s.at(i) == s.at(j)) {
            //往左边移动
            i--;
            // 往右边移动
            j++;
            continue;
        }
    }

    return vector<int>{i + 1, j - i - 1};
}

string Solution::longestPalindrome3(string s) {
    size_t len = s.size();
    if (len < 2) {
        return s;
    }

    vector<int> max(2, 0);
    for (int    i = 0; i < len; ++i) {
        vector<int> odd  = centerSpread3(s, i, i);
        vector<int> even = centerSpread3(s, i, i + 1);
        vector<int> temp = odd.at(1) > even.at(1) ? odd : even;

        if (temp.at(1) > max.at(1)) {
            max = temp;
        }
    }


    return s.substr(max[0], max[1]);
}

vector<int> Solution::centerSpread3(string s, int i, int j) {
    vector<int> result(2, 0);
    int         len = s.size();
    while (i >= 0 && j < len) {
        if (s.at(i) == s.at(j)) {
            i--;
            j++;
            continue;
        } else{
            break;
        }
    }
    return vector<int>{i + 1, j - i - 1};
}







