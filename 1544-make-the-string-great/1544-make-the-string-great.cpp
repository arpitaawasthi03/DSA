class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        if(st.empty()) st.push(s[0]);
        for(int i=1; i<s.length(); i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};