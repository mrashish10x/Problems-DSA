class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0; // unmatched '(' waiting for ')'
        int insertions = 0; // moves needed so far
        
        for (char c : s) {
            if (c == '(') {
                openNeeded++;
            } else { // c == ')'
                if (openNeeded > 0) {
                    openNeeded--; // matches an existing unmatched '('
                } else {
                    insertions++; // no '(' to match, need to insert one
                }
            }
        }
        
        // any remaining unmatched '(' need a corresponding ')' inserted
        insertions += openNeeded;
        
        return insertions;
    }
};