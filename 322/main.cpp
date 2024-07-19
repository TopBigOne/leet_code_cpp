#include <iostream>
#include <vector>

using namespace std;


int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (auto item: coins) {
            if (item <= i && dp[i - item] != -1) {
                if (dp[i] == -1 || dp[i] > dp[i - item] + 1) {
                    dp[i] = dp[i - item] + 1;
                }
            }
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    int minType = coinChange(coins, 11);
    cout << "minType : " << minType << endl;
    return 0;
}
