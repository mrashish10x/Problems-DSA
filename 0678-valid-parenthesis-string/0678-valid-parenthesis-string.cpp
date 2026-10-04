class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // '*'
                minOpen--;
                maxOpen++;
            }
            
            if (maxOpen < 0) return false; // too many ')' even in best case
            minOpen = max(minOpen, 0); // can't go below 0 since '*' can be treated as empty
        }
        
        return minOpen == 0;
    }
};