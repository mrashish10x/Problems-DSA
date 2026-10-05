class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        stk.push(0); // base score at current level
        
        for (char c : s) {
            if (c == '(') {
                stk.push(0); // start a new nested level
            } else {
                int inner = stk.top();
                stk.pop();
                int score = (inner == 0) ? 1 : 2 * inner;
                stk.top() += score; // add this completed group's score to the enclosing level
            }
        }
        
        return stk.top();
    }
};