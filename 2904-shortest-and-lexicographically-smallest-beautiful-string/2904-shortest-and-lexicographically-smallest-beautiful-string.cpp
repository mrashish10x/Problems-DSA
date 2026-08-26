class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string best = "";
        int bestLen = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1') ones++;
                if (ones == k) {
                    string cur = s.substr(i, j - i + 1);
                    int curLen = cur.size();
                    if (curLen < bestLen) {
                        bestLen = curLen;
                        best = cur;
                    } else if (curLen == bestLen && cur < best) {
                        best = cur;
                    }
                    break; // longer substrings from same i will have more 1's, no need to continue
                }
            }
        }
        
        return best;
    }
};