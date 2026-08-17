class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n , 0);
        vector<int>right(n ,0);

        stack<int>st;
        int ans =0;

        for(int i = 0 ; i < n ; i++){
            while(st.size()>0 && st.top() < height[i]){
                st.pop();
            }
            
            left[i] = st.empty() ? height[i] : st.top();
            if(st.empty() || st.top() < height[i]){
                st.push(height[i]);
            } 

        }

        while(!st.empty()){
            st.pop();
        }


        for(int i = n-1 ; i >= 0 ; i--){
            while(st.size()>0 && st.top() < height[i]){
                st.pop();
            }
            
            right[i] = st.empty() ? height[i] : st.top();
            if(st.empty() || st.top() < height[i]){
                st.push(height[i]);
            } 

        }

        for(int i = 0 ; i < n ; i++){
            ans += min(left[i] , right[i]) - height[i];
        }

        return ans;
    }
};