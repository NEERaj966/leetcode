class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,0);

        for(int i = 2*n-1 ; i >= 0 ; i--){
            while(st.size() > 0 && st.top() <= nums[i%n]){
                st.pop();
            }

            ans[i%n] = st.empty() ? -1 : st.top();

            st.push(nums[i%n]);
        }

        return ans;
    }
};