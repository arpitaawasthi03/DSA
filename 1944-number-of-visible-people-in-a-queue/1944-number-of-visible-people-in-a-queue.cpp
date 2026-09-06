class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            int c=0;
            while(st.size() && st.top()<=heights[i]){
                c++;
                st.pop();
            }
            if(st.size())c++;
            ans[i]=c;
            st.push(heights[i]);
        }
        return ans;
    }
};