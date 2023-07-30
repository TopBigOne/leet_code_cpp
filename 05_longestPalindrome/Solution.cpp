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

    for (int    i = 0; i < len; ++i) {
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







