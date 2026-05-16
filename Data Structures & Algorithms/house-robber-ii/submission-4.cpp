#include <cstring> 
class Solution {
public:
    int dp[105];
    int n;
    bool k = false;

    int f(int i, vector<int>& nums) {
        if (i == 0) {
            k = true;
        }

        if (k) {
            if (i == n - 1) {
                return 0;
            }
            if (i > n - 1) {
                return 0;
            }
        } else {
            if (i > n - 1) {
                return 0;
            }
        }

        int& ans = dp[i];
        if (ans != -1) return ans;

        ans = max(f(i + 1, nums), f(i + 2, nums) + nums[i]);
        return ans;
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return nums[0];

        memset(dp, -1, sizeof dp);
        k = false;
        int ans1 = f(0, nums);

        memset(dp, -1, sizeof dp);
        k = false;
        int ans2 = f(1, nums);

        return max(ans1, ans2);
    }
};