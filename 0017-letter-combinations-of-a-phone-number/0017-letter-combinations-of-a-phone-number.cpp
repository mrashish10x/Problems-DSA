class Solution {
private:
    vector<string> answer;
    string digits;

    string getsletters(char digit){
        switch(digit){
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
        }
        return "";
    }

    void generateStrings(int i, string &current){
        if(i == digits.length()){
            answer.push_back(current);
            return;
        }

        string letters = getsletters(digits[i]);

        for(int j = 0; j < letters.length(); j++){
            current.push_back(letters[j]);   
            generateStrings(i + 1, current);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits){
        if(digits.empty()) return {};  

        this->digits = digits;
        answer.clear();

        string current = "";
        generateStrings(0, current);

        return answer;
    }
};