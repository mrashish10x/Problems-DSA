class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0); // dp[r] = count of subarrays ending at previous index with product % k == r
        
        for (int i = 0; i < n; i++) {
            vector<long long> newDp(k, 0);
            int val = nums[i] % k;
            
            // subarray consisting of just nums[i] itself
            newDp[val] += 1;
            
            // extend all subarrays ending at i-1
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newR = (int)(((long long)r * val) % k);
                    newDp[newR] += dp[r];
                }
            }
            
            dp = newDp;
            
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }
        
        return result;
    }
};