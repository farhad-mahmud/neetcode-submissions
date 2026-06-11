class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<string> p;

        for (int i = 0; i < n; i++) {
            string t = "";
            t += s[i];
            for (int j = i + 1; j < n; j++) {
                t += s[j];
                string rev = t;
                reverse(rev.begin(), rev.end());

                if (t == rev) {
                    p.push_back(t);
                }
            }
        }

        sort(p.begin(), p.end());

        string ans = "";
        int mx = 0;
        for (auto ss : p) {
            if ((int)ss.size() > mx) {
                mx = ss.size();
                ans = ss;
            }
        }

        if (ans.empty() && !s.empty()) {
            ans = s[0];
        }

        return ans;
    }
};