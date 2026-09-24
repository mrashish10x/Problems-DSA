class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            int digitSum = 0;
            int val = nums[i];
            if (val == 0) digitSum = 0;
            while (val > 0) {
                digitSum += val % 10;
                val /= 10;
            }
            if (digitSum == i) return i;
        }
        return -1;
    }
};