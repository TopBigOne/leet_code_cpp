//
// Created by dev on 2023/7/15.
//

#ifndef INC_05_THREESUM_LEET_CODE_UTILS_H
#define INC_05_THREESUM_LEET_CODE_UTILS_H

#include <vector>

#include <iostream>

using namespace std;


/**
 * 打印一维数组
 * @return
 */
template<typename T>
void print_v(vector<T> &nums) {
    cout << "[";
    for (const auto &item: nums) {
        cout << item << " ";
    }
    cout << "]" << endl;
}

/**
 * 打印二维数组
 * @return
 */
template<typename T>
void print_v2(vector<vector<T>> &nums) {
    for (const auto &item: nums) {
        cout << "[";
        for (const auto &innerItem: item) {
            cout << innerItem << " ";
        }
        cout << "]" << endl;
    }
}


#endif //INC_05_THREESUM_LEET_CODE_UTILS_H

