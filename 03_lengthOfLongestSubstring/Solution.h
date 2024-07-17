//
// Created by dev on 2024/7/16.
//

#ifndef INC_03_LENGTHOFLONGESTSUBSTRING_SOLUTION_H
#define INC_03_LENGTHOFLONGESTSUBSTRING_SOLUTION_H

#include <string>

using namespace std;


/**
 * 无重复字符的最长子串 ：https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
 * 输入: s = "abc abc bb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

 滑动窗口


 * @return
 */
class Solution {
public:
    /**
     * 滑动窗口
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(string s);

    int lengthOfLongestSubstring2(string s);

    int lengthOfLongestSubstring3(string s);
    int lengthOfLongestSubstring4(string s);

};


#endif //INC_03_LENGTHOFLONGESTSUBSTRING_SOLUTION_H
