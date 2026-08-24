class Solution {
public:
    long long stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + stones[i];
        
        vector<long long> dp(n + 1, 0);
        vector<long long> sufMax(n + 2, LLONG_MIN);
        
        // dp[n] = 0, base case
        sufMax[n] = prefix[n] - dp[n]; // = prefix[n]
        
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = sufMax[i + 1];
            long long g = prefix[i] - dp[i];
            sufMax[i] = max(g, sufMax[i + 1]);
        }
        
        // dp[0] = max over i' in [2, n] of (prefix[i'] - dp[i']) = sufMax[2]
        return sufMax[2];
    }
};