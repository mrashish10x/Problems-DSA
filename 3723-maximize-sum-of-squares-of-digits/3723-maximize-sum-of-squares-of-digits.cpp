class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        return sum>9*num?"":(string(sum/9,'9')+char('0'+sum%9)+string(num,'0')).substr(0,num);
    }
};