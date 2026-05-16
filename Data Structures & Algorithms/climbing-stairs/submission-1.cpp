#include <cstring>

class Solution {
private:
    int dp[50];

    int f(int i) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (dp[i] != -1) return dp[i];
        return dp[i] = f(i - 1) + f(i - 2);
    }

public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return f(n);
    }
};