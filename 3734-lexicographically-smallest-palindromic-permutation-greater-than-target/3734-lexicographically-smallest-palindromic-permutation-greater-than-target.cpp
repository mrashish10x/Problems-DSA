class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++) if (cnt[c] % 2 == 1) { oddCount++; oddChar = c; }
        
        bool isOdd = (n % 2 == 1);
        if ((isOdd && oddCount != 1) || (!isOdd && oddCount != 0)) return "";
        
        int half = n / 2;
        vector<int> avail(26);
        for (int c = 0; c < 26; c++) avail[c] = cnt[c] / 2;
        char midChar = isOdd ? ('a' + oddChar) : 0;
        
        vector<char> P(half);
        vector<int> curAvail = avail;
        bool matchedFull = true;
        
        int bestPos = -1; char bestChar = 0; vector<int> bestAvail;
        
        for (int i = 0; i < half; i++) {
            int t = target[i] - 'a';
            for (int c = t + 1; c < 26; c++) {
                if (curAvail[c] > 0) {
                    bestPos = i; bestChar = 'a' + c;
                    bestAvail = curAvail; bestAvail[c]--;
                    break;
                }
            }
            if (curAvail[t] > 0) { curAvail[t]--; P[i] = 'a' + t; }
            else { matchedFull = false; break; }
        }
        
        if (matchedFull) {
            int pos = half;
            bool forcedValid = false, forcedFailed = false;
            int divergePos = -1; char divergeChar = 0;
            if (isOdd) {
                char actual = midChar, t = target[pos];
                if (actual > t) { forcedValid = true; divergePos = pos; divergeChar = actual; }
                else if (actual < t) forcedFailed = true;
                pos++;
            }
            if (!forcedValid && !forcedFailed) {
                for (; pos < n; pos++) {
                    int mirrorIdx = n - 1 - pos;
                    char actual = P[mirrorIdx], t = target[pos];
                    if (actual > t) { forcedValid = true; divergePos = pos; divergeChar = actual; break; }
                    else if (actual < t) { forcedFailed = true; break; }
                }
            }
            if (forcedValid) {
                string result = target.substr(0, divergePos);
                result += divergeChar;
                for (int p = divergePos + 1; p < n; p++) {
                    if (isOdd && p == half) result += midChar;
                    else result += P[n - 1 - p];
                }
                return result;
            }
        }
        
        if (bestPos == -1) return "";
        
        string result = target.substr(0, bestPos);
        result += bestChar;
        for (int c = 0; c < 26; c++)
            for (int k = 0; k < bestAvail[c]; k++) result += (char)('a' + c);
        
        if (isOdd) result += midChar;
        string firstHalfStr = result.substr(0, half);
        for (int i = half - 1; i >= 0; i--) result += firstHalfStr[i];
        
        return result;
    }
};