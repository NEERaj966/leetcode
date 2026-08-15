class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> st;

        // right smallest
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            right[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while(st.size()>0){
            st.pop();
        }

        // left smaller 
        for (int i = 0; i<n; i++) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            left[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            int w = right[i] - left[i]-1;
            int curr = heights[i] * w;

            ans = max(curr , ans);
        }

        return ans;
    }
};