#include <iostream>
#include <string>
#include <unordered_set>
#include "Solution.h"

using namespace std;

#include <vector>




int main() {
    string s = "abcabcab";
    s = " ";
    Solution solution;
    int      result = solution.lengthOfLongestSubstring(s);
    cout << "result:" << result << endl;

    return 0;
}
