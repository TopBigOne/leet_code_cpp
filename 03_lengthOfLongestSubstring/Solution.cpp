//
// Created by dev on 2024/7/16.
//

#include "Solution.h"
#include <vector>

int Solution::lengthOfLongestSubstring(string s) {
    int    maxLength = 0;
    size_t len;
    if ((len = s.length()) == 0) {
        return maxLength;
    }
    int left  = 0;
    int right = 0;

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


/**
 * 无重复最长子串
 * @param s
 * @return
 */
int Solution::lengthOfLongestSubstring2(string s) {

    int    maxLength = 0;
    size_t len       = 0;
    if ((len = s.size()) == 0) {
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


int Solution::lengthOfLongestSubstring3(string s) {
    int maxLength = 0;
    int len;
    if ((len = s.length()) < 0) {
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


int Solution::lengthOfLongestSubstring4(string s) {
    int maxLength = 0;
    int len       = 0;
    if ((len = s.length()) == 0) {
        return maxLength;
    }

    vector<int> window(256);
    int         left  = 0;
    int         right = 0;
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













