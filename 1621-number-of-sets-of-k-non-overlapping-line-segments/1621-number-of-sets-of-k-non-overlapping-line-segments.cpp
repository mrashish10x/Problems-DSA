class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
        
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        
        for (int j = 1; j <= k; j++) {
            long long runningSum = 0; // sum of dp[q][j-1] for q = 1..i-1
            dp[0][j] = 0;
            for (int i = 1; i <= n; i++) {
                dp[i][j] = (dp[i-1][j] + runningSum) % MOD;
                runningSum = (runningSum + dp[i][j-1]) % MOD;
            }
        }
        
        return (int)dp[n][k];
    }
};