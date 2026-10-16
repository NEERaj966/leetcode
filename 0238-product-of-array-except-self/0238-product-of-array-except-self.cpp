class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int>sufix(n);
        int pro = 1;

        for(int i = 0 ; i < n ; i++){
            prefix[i] = pro;
            pro *= nums[i];
        }

        pro = 1;
        
        for(int i = n-1 ; i >= 0 ; i--){
            sufix[i] = pro*prefix[i];
            pro *= nums[i];
        }

        return sufix;

    }
};