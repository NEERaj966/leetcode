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
        subsets(nums , ans , set , i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> set;

        subsets(nums , ans , set , 0);

        return ans;        
    }
};