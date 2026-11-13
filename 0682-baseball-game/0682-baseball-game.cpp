class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string op: operations){
            if(op=="C") st.pop();
            else if(op=="D") st.push(2*(st.top()));
            else if(op=="+"){
                int top = st.top();
                st.pop();
                int sum = top+st.top();
                st.push(top);
                st.push(sum);
            }
            else st.push(stoi(op));
        }
        int score = 0;
        while(st.size()>0){
            score+=st.top();
            st.pop();
        }
        return score;

    }
};