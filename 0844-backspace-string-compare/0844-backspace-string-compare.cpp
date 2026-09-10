class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st;

        // Process s
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '#') {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(s[i]);
            }
        }

        string a = "";

        while(!st.empty()) {
            a += st.top();
            st.pop();
        }

        reverse(a.begin(), a.end());

        // Process t
        for(int i = 0; i < t.length(); i++) {
            if(t[i] == '#') {
                if(!st.empty()) {
                    st.pop();
                }
            }
            else {
                st.push(t[i]);
            }
        }

        string b = "";

        while(!st.empty()) {
            b += st.top();
            st.pop();
        }

        reverse(b.begin(), b.end());

        return a == b;
    }
};