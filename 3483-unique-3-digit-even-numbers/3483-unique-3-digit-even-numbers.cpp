class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt[10] = {0};
        for (int d : digits) cnt[d]++;
        
        int result = 0;
        
        for (int h = 1; h <= 9; h++) {          // hundreds digit: no leading zero
            for (int t = 0; t <= 9; t++) {       // tens digit
                for (int u = 0; u <= 8; u += 2) { // units digit: must be even
                    int need[10] = {0};
                    need[h]++;
                    need[t]++;
                    need[u]++;
                    
                    bool ok = true;
                    for (int d = 0; d < 10; d++) {
                        if (need[d] > cnt[d]) { ok = false; break; }
                    }
                    
                    if (ok) result++;
                }
            }
        }
        
        return result;
    }
};