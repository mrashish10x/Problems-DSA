class Solution {
public:
    int minInsertions(string s) {
        long long insertions = 0;
        long long open = 0; // unmatched '(' so far
        int n = s.size();
        int i = 0;
        
        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } else {
                // s[i] == ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2; // already have "))"
                } else {
                    insertions++; // need to insert one ')' to complete "))"
                    i += 1;
                }
                
                if (open > 0) {
                    open--;
                } else {
                    insertions++; // need to insert a '(' to match this "))"
                }
            }
        }
        
        // each remaining unmatched '(' needs "))" inserted
        insertions += open * 2;
        return (int)insertions;
    }
};