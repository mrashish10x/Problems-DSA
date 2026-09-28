class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int d = 0;

        for (char c : s) {
            d += c == '(';
            res = max(res, d);
            d -= c == ')';
        }

        return res;
    }
};