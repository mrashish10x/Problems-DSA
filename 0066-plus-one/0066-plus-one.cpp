class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        vector<int>answer(digits.size());
        int i = digits.size()-1;

        while(i>=0){
            int sum=digits[i]+carry;
            int digit=sum%10;
            carry=sum/10;

            answer[i]=digit;
            i--;

        }
        if(carry!=0){
            answer.insert(answer.begin(),carry);
        }
        return answer;
    }
};