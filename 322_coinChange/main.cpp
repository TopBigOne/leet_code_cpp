#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

/**
 * https://leetcode.cn/problems/coin-change/description/
 */
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        // base corner
        if (coins.empty()) {
            return 0;
        }
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            // 面值： coin_value
            for (const auto &coin_value: coins) {
                // case 1:
                if (coin_value > i) {
                    continue;
                }
                // case 2 : ok
                dp[i] = min(dp[i], dp[i - coin_value] + 1);
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];

    }

    int coinChange2(vector<int> &coins, int amount) {
        // 数组大小为 amount + 1，初始值也为 amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        // 外层 for 循环在遍历所有状态的所有取值
        for (int i = 0; i < dp.size(); i++) {
            for (int coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];

    }

    int coinChange3(vector<int> &coins, int amount) {
        // base corner.
        if (coins.empty()) {
            return 0;
        }
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto &coin_value: coins) {
                if (coin_value > i) {
                    continue;
                }
                // +1 : select one coin and increase it .
                dp[i] = min(dp[i], dp[i - coin_value] + 1);
            }
        }
        // bad case :
        if (amount + 1 == dp[amount]) {
            return -1;
        }
        return dp[amount];
    }

    int coinChange4(vector<int> &coins, int amount) {
        if (coins.empty()) {
            return 0;
        }
        int         max = amount + 1;
        vector<int> dp(max, max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (const auto &value: coins) {
                if (value > i) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - value] + 1);
            }
        }

        if (dp[amount] == max) {
            return 0;
        }

        return dp[amount];

    }


    int coinChange5(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i < = amount; ++i) {
            for (const auto &value: coins) {
                if (value > i) {
                    continue;
                }
                // 其中，dp[i - value] + 1 表示使用当前硬币面额 value 兑换金额 i 所需的硬币数量。
                dp[i] = min(dp[i], dp[i - value] + 1);
            }
        }
        if (dp[amount] == amount + 1) {
            return 0;
        }
        return dp[amount];
    }


    int coinChange6(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto &value: coins) {
                if (value > i) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - value] + 1);
            }

        }
        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];


    }


    int coinChange7(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        if (coins.size() == 0) {
            return -1;
        }
        // init.
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (const auto &value: coins) {
                if (value > i) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - value] + 1);
            }
        }

        if (dp[amount] == amount + 1) {
            return -1;
        }
        return dp[amount];
    }
};

int main() {
    Solution    solution;
    vector<int> coins{1, 2, 5};
    int         amount = 11;

    int result = solution.coinChange3(coins, amount);
    cout << "result : " << result << endl;
    result = solution.coinChange6(coins, amount);
    cout << "result : " << result << endl;

    return 0;
}
