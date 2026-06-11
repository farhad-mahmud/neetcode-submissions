class Solution {
public:
    vector<vector<int>> dp;
    int n, m;

    int f(int i, int j) {
        if (i > n || j > m) {
            return 0;
        }
        if (i == n && j == m) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = f(i + 1, j);
        ans += f(i, j + 1);

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) {
        this->n = n;
        this->m = m;
        
        dp.assign(n + 1, vector<int>(m + 1, -1));
        
        return f(1, 1);
    }
};