#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string vow   = "aeiouAEIOU";
        int    left  = 0;
        int    right = s.length() - 1;
        while (left < right) {

            while (left < right && vow.find(s.at(left)) == string::npos) {
                left++;
            }

            while (left < right && vow.find(s.at(right)) == string::npos) {
                right--;
            }
            char c = s.at(left);
            s[left]  = s.at(right);
            s[right] = c;
            left++;
            right--;
        }
        return s;
    }

    string reverseVowels2(string s) {
        std::string vow   = "aeiouAEIOU";
        int         left  = 0;
        int         right = s.length() - 1;

        while (left < right) {
            while (left < right && vow.find(s[left]) == std::string::npos) {
                left++;
            }

            while (left < right && vow.find(s[right]) == std::string::npos) {
                right--;
            }

            char c = s[left];
            s[left]  = s[right];
            s[right] = c;
            left++;
            right--;
        }

        return s;
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
