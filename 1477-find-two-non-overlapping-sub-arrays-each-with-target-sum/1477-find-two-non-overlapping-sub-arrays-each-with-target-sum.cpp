class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLenEndingAt(n, INT_MAX); // minLenEndingAt[i] = min length of a subarray with sum=target that ends at or before index i
        
        int left = 0;
        long long sum = 0;
        int best = INT_MAX;
        int ans = INT_MAX;
        
        vector<int> minLen(n, INT_MAX); // minLen[i] = minimum length subarray with sum=target ending exactly at index i, or INT_MAX
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            
            if (sum == target) {
                int len = right - left + 1;
                // if there's a valid subarray ending before 'left', combine
                if (left > 0 && minLenEndingAt[left - 1] != INT_MAX) {
                    ans = min(ans, len + minLenEndingAt[left - 1]);
                }
                best = min(best, len);
            }
            
            minLenEndingAt[right] = best;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};