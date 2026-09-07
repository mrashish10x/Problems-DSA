class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> f(n + 1, 0);
        f[0] = 1;
        
        vector<int> lastOccurrence(26, -1); // stores i (1-indexed position) of last occurrence, -1 if none
        
        for (int i = 1; i <= n; i++) {
            int c = s[i-1] - 'a';
            f[i] = (2 * f[i-1]) % MOD;
            if (lastOccurrence[c] != -1) {
                f[i] = (f[i] - f[lastOccurrence[c] - 1] + MOD) % MOD;
            }
            lastOccurrence[c] = i;
        }
        
        int ans = (int)((f[n] - 1 + MOD) % MOD);
        return ans;
    }
};