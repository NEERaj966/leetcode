class Solution {
public:
    int jump(vector<int>& nums) {
        int minjump = 0;
        int left = 0 , right = 0;
        int n = nums.size();

        while(right < n-1){
            int far = 0;

            for(int i = left ; i <= right ; i++){
                far = max(far , i+nums[i]);
            }
            left = right+1;
            right = far;
            minjump = minjump+1;
        }
        return minjump;
    }
};