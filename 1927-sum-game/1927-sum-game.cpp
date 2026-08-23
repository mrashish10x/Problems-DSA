class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        long long sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') cnt1++;
            else sum1 += (num[i] - '0');
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') cnt2++;
            else sum2 += (num[i] - '0');
        }
        
        int q = cnt1 + cnt2;
        
        // If total '?' count is odd, Alice always wins
        if (q % 2 == 1) return true;
        
        long long diff = sum1 - sum2;
        long long need = 9LL * (cnt2 - cnt1) / 2;
        
        return diff != need;
    }
};