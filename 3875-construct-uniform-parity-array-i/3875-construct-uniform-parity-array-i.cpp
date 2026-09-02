class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int cnt0 = 0, cnt1 = 0;
        for (int x : nums1) {
            if (x % 2 == 0) cnt0++;
            else cnt1++;
        }
        
        // Case 1: n == 1, or all same parity -> just use nums2 = nums1
        if (cnt0 == 0 || cnt1 == 0) return true;
        
        // Case 2: mixed parities -> target all-odd (T=1) is always achievable:
        // - odd elements keep their own value
        // - even elements pair with any odd element (which always exists and differs from itself)
        return true;
    }
};