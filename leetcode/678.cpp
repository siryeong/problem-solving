class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i]=='(') st.push(i);

            if(s[i]==')' && !st.empty()) {
                int o = st.top(); st.pop();
                s[o] = '.';
                s[i] = '.';
            }
        }

        for(int i = 0; i < s.length(); i++) { 
            if(s[i] == '(') 
                for(int j = i+1; j < s.length(); j++) 
                    if(s[j]=='*') {
                        s[i] = s[j] = '.';
                        break;
                    }
            if(s[i] == ')') 
                for(int j = i-1; j > -1; j--) 
                    if(s[j]== '*') {
                        s[i] = s[j] = '.';
                        break;
                    }       
        }

        for(int i = 0; i < s.length(); i++) 
            if(s[i] == '(' || s[i] == ')') 
                return false;
        return true;
    }
};