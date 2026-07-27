class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low = 0; int high = n-1;
        int start = -1;
        vector<int> v;
        //search for first element.
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                start = mid;
                high = mid-1; //check if there any target element in left
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        } 
    
        //search for last element.
        low = 0; high = n-1; //reset low and high.
        int end = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                end = mid; 
                low = mid+1;  //check if there any target element in right.
            }
            else if(nums[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        v = {start,end};
        return v;
        
    }
};