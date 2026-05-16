class Solution {
public:
    vector<int> nums;
    vector<int> dp;
    int n;

    int f(int i) {
        if (i >= n) return 0;
        
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(f(i + 1), f(i + 2) + nums[i]);
    }

    int rob(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        dp.assign(n + 2, -1);

        return f(0);
    }
};