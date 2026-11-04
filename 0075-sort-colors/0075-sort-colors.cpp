class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();
        int i=0,j=n-1,k=0;
        while(k <= j){
            if(arr[k] == 0){
                swap(arr[i] , arr[k]);
                i++;
                k++;
            }
            else if(arr[k] == 1){
                k++;
            }
            else{
                swap(arr[k] , arr[j]);
                j--;
            }
        }
    }
};