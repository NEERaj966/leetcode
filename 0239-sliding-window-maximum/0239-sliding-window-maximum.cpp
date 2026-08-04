class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> Q;
        vector<int> ans;

        for(int i =0 ; i < k  ; i++){
            while(!Q.empty() && nums[Q.back()] <= nums[i]){
                Q.pop_back();
            }

            Q.push_back(i);
        }

        for(int i = k ; i < nums.size(); i++){
            ans.push_back(nums[Q.front()]);

            while(!Q.empty() && Q.front() <= i-k){
                Q.pop_front();
            }
            
             while(!Q.empty() && nums[Q.back()] <= nums[i]){
                Q.pop_back();
            }

            Q.push_back(i);


        }

        ans.push_back(nums[Q.front()]);

        return ans;
    }
};