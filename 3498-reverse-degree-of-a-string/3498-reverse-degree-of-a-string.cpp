class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int revAlphaPos = 26 - (s[i] - 'a'); // 'a'->26, 'b'->25, ..., 'z'->1
            int strPos = i + 1; // 1-indexed position in string
            total += revAlphaPos * strPos;
        }
        return total;
    }
};