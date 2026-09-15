class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i < 2) pal[i][j] = true;
                    else pal[i][j] = pal[i+1][j-1];
                } else {
                    pal[i][j] = false;
                }
            }
        }
        
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            for (int j = i - k; j >= 0; j--) {
                if (pal[j][i-1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    break;
                }
            }
        }
        
        return dp[n];
    }
};