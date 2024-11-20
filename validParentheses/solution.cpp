class Solution {
public:
    bool isValid(string s) {

        stack<char> parantheses; 

        if (s.length() % 2 != 0) return false;

        if ((s[0] == ')') or (s[0] == '}') or (s[0] == ']'))
            return false;

        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == '(') or (s[i] == '{') or (s[i] == '[')) {
                parantheses.push(s[i]);
            }

            if (parantheses.empty()) return false;

            if (s[i] == ')') 
                if (parantheses.top() == '(')
                    parantheses.pop();
                else
                    return false;
            if (s[i] == ']') 
                if (parantheses.top() == '[')
                    parantheses.pop();
                else
                    return false;
            if (s[i] == '}') 
                if (parantheses.top() == '{')
                    parantheses.pop();
                else
                    return false;
            }
        if (parantheses.empty())
            return true;   

        return false;
    }
};

