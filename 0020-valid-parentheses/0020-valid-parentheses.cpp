class Solution {
public:
    bool isValid(string s) {
        // Use a fixed-size array as stack instead of std::stack for speed
        char stack[10001];
        int top = -1;
        
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack[++top] = c;
            } else {
                if (top == -1) return false;
                
                char last = stack[top];
                if ((c == ')' && last != '(') ||
                    (c == '}' && last != '{') ||
                    (c == ']' && last != '['))
                    return false;
                
                top--;
            }
        }
        
        return top == -1;
    }
};