class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        if (l == 0) return 0;

        vector<vector<bool>> dp(l, vector<bool>(l, false));

        for (int i = 0; i < l; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < l - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }

        for (int len = 3; len <= l; len++) {
            for (int i = 0; i <= l - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (dp[i][j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};