class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        int i = min(minIdx, maxIdx);
        int j = max(minIdx, maxIdx);
        
        // Option 1: remove both from the front (up to and including j)
        int option1 = j + 1;
        
        // Option 2: remove both from the back (from i to end)
        int option2 = n - i;
        
        // Option 3: remove one from front (up to i) and one from back (from j)
        int option3 = (i + 1) + (n - j);
        
        return min({option1, option2, option3});
    }
};