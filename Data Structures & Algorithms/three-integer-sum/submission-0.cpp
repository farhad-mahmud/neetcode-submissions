class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i].first = nums[i];
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && a[i].first == a[i - 1].first) continue;
            int t = 0 - a[i].first;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = a[l].first + a[r].first;
                if (sum == t) {
                    ans.push_back({a[i].first, a[l].first, a[r].first});
                    while (l < r && a[l].first == a[l + 1].first) l++;
                    while (l < r && a[r].first == a[r - 1].first) r--;
                    l++;
                    r--;
                } else if (sum < t) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ans;
    }
};