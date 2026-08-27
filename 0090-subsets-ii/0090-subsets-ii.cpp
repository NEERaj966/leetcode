class Solution {
public:
    void subsets(vector<int>& nums , vector<vector<int>> & ans , vector<int> set , int i){
        if(i == nums.size()){
            ans.push_back(set);
            return;
        }

        set.push_back(nums[i]);
        subsets(nums , ans , set , i+1);

        set.pop_back();

        int idx = i+1;

        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        subsets(nums , ans , set , idx);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> set;
        subsets(nums , ans , set , 0);

        return ans;
    }
};