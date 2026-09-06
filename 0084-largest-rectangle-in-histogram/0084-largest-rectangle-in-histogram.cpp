class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {

        int n = hts.size();

        vector<int> nse(n);
        stack<int> st1;

        for (int i = n - 1; i >= 0; i--) {

            while (st1.size() > 0 && hts[st1.top()] >= hts[i]) {
                st1.pop();
            }

            if (st1.size() == 0) {
                nse[i] = n;
            } 
            else {
                nse[i] = st1.top();
            }

            st1.push(i);
        }

        vector<int> pse(n);
        stack<int> st2;

        for (int i = 0; i < n; i++) {

            while (st2.size() > 0 && hts[st2.top()] >= hts[i]) {
                st2.pop();
            }

            if (st2.size() == 0) {
                pse[i] = -1;
            } 
            else {
                pse[i] = st2.top();
            }

            st2.push(i);   // FIX
        }

        // Calculate maximum area
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            int width = nse[i] - pse[i] - 1;

            int area = hts[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};