class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         vector<vector<int>> v;
         for(int i=0 ; i < nums.size() ; i++){
            v.push_back({nums[i], i});
         }

         sort(v.begin() , v.end());

         int i = 0;
         int j = v.size()-1;
         vector<int> ans;

         while(i != j && i < v.size() && j > 0){
            int sum = v[i][0]+v[j][0];
            if(sum == target){
                ans.push_back(v[i][1]);
                ans.push_back(v[j][1]);
                break;
            }
            else if(sum > target){
                j--;
            }else if(sum < target){
                i++;
            }

         }
         return ans;
    }
};