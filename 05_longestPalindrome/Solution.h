//
// Created by dev on 2023/7/30.
//

#include <string>
#include <vector>

using namespace std;

#ifndef INC_05_LONGESTPALINDROME_SOLUTION_H
#define INC_05_LONGESTPALINDROME_SOLUTION_H

class Solution {
public:
    Solution();

    string longestPalindrome(string s);


/**
 * 中心扩散法
 * @param basicString
 * @param i
 * @param i1
 * @return
 */
    vector<int> centerSpread(string basicString, int i, int j);


    string longestPalindrome2(string s);

    vector<int> centerSpread2(string basicString, int i, int j);




    string longestPalindrome3(string s);

    vector<int> centerSpread3(string basicString, int i, int j);
};


#endif //INC_05_LONGESTPALINDROME_SOLUTION_H
