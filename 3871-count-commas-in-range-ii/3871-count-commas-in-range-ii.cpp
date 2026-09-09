class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long low = 1, high = 9; // 1-digit numbers: 1 to 9
        int L = 1;
        
        while (low <= n) {
            long long curHigh = min(high, n);
            long long count = curHigh - low + 1;
            int commasPerNumber = (L - 1) / 3;
            total += count * (long long)commasPerNumber;
            
            // advance to next digit-length bracket
            low = high + 1;
            high = high * 10 + 9;
            L++;
        }
        
        return total;
    }
};