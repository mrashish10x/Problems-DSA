class Solution {
public:
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        
        vector<string> result;
        bool found = false;
        
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                
                if (isValid(cur)) {
                    result.push_back(cur);
                    found = true;
                }
                
                if (found) continue; // don't expand further once we've found valid strings at this level
                
                for (int j = 0; j < (int)cur.size(); j++) {
                    if (cur[j] != '(' && cur[j] != ')') continue;
                    string next = cur.substr(0, j) + cur.substr(j + 1);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            
            if (found) break; // stop BFS once we've found valid strings at the minimal removal level
        }
        
        return result;
    }
};