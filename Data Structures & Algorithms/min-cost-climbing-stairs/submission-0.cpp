#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dp[102];
    int n;
    vector<int> a;

    int f(int i) {
        if (i == n + 1 || i == n) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = min(f(i + 1) + a[i], f(i + 2) + a[i]);
        return dp[i] = ans;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        a = cost;
        n = a.size();
        memset(dp, -1, sizeof(dp));

        int ans1 = f(0);
        int ans2 = f(1);

        return min(ans1, ans2);
    }
};