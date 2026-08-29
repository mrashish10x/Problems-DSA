class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> arr(n); // (value, original index)
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());
        
        vector<int> result(n);
        int i = 0;
        while (i < n) {
            int j = i;
            // Extend the group while consecutive sorted values differ by <= limit
            while (j + 1 < n && arr[j+1].first - arr[j].first <= limit) {
                j++;
            }
            // Group is arr[i..j], collect their original indices, sort them
            vector<int> indices;
            for (int k = i; k <= j; k++) indices.push_back(arr[k].second);
            sort(indices.begin(), indices.end());
            
            // Assign sorted values (already sorted since arr is sorted by value)
            // to sorted indices in order
            for (int k = 0; k < (int)indices.size(); k++) {
                result[indices[k]] = arr[i + k].first;
            }
            
            i = j + 1;
        }
        
        return result;
    }
};