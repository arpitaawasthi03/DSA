class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> st;
        if (st.empty()){
            st.push(str[0]);
        }
        for (int i = 1; i < str.length(); i++) {
            if ( !st.empty() && st.top() == str[i]) {
                st.pop();
            } else {
                st.push(str[i]);
            }
        }
        string ans = "";
        while (!(st.empty())) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};