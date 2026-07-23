class Solution {
public:

    void nextPermutation(vector<int>& nums) {
        int pivot = -1, n = nums.size();

        // Find the pivot
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                pivot = i - 1;
                break;
            }
        }

        // If no pivot exists, reverse the entire array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the rightmost element greater than the pivot
        int t = n - 1;
        while (nums[pivot] >= nums[t]) {
            t--;
        }

        // Swap pivot with the next greater element
        swap(nums[pivot], nums[t]);

        // Reverse the suffix
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
    
