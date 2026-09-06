class Solution {
public:
    bool validPair(char opening, char closing){
        if(opening == '(' && closing == ')') return true;
        if(opening == '[' && closing == ']') return true;
        if(opening == '{' && closing == '}') return true;
        else return false;
    }
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n%2 == 1) return false;
        for(char ch: s){
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }else{
                if(st.size() == 0) return false;
                if(validPair(st.top(),ch)) st.pop();
                else return false;
            }
        }
        return (st.size() == 0);
    }
};