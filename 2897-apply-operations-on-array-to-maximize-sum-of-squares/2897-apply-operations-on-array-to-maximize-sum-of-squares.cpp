class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> cnt(31, 0); // cnt[b] = how many numbers have bit b set
        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x >> b & 1) cnt[b]++;
            }
        }
        
        long long ans = 0;
        for (int t = 0; t < k; t++) {
            long long cur = 0;
            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    cur |= (1LL << b);
                    cnt[b]--;
                }
            }
            cur %= MOD;
            ans = (ans + cur * cur) % MOD;
        }
        return (int)ans;
    }
};