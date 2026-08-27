class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        
        int bestPos = -1;
        char bestChar = 0;
        vector<int> bestRemaining(26, 0);
        
        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            
            // Find smallest character greater than target[i] that's still available
            for (int c = t + 1; c < 26; c++) {
                if (count[c] > 0) {
                    bestPos = i;
                    bestChar = 'a' + c;
                    bestRemaining = count;      // snapshot BEFORE using this char
                    bestRemaining[c]--;         // use it for the candidate
                    break;
                }
            }
            
            // Try to continue matching target exactly
            if (count[t] > 0) {
                count[t]--;
            } else {
                break; // can't match exactly anymore, stop extending prefix
            }
        }
        
        if (bestPos == -1) return "";
        
        string result = target.substr(0, bestPos);
        result += bestChar;
        for (int c = 0; c < 26; c++) {
            result += string(bestRemaining[c], 'a' + c);
        }
        
        return result;
    }
};