class Solution {
public:
    bool isValid(string s) {
      if(s.size()%2==1) return false;
        stack<char> st;
        for(char ch:s){
            if(ch=='(' or ch=='[' or ch=='{') st.push(ch);
            else{
                if(st.size()==0) return false;
                else if(ch==')' and st.top()=='(') st.pop();
                else if(ch==']' and st.top()=='[') st.pop();
                else if(ch=='}' and st.top()=='{') st.pop();
                else return false;
            }
        }
        return (st.size()==0);
    }
};