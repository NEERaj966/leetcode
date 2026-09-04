class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxel(n);
        vector<int> minel(n);

        int maxi = nums[0];
        maxel[0] = maxi;


        for(int i = 1 ; i < n ; i++){
            maxi = max(maxi , nums[i]);
            maxel[i] = maxi;
        }

        int mini = nums[n-1];
        minel[n-1] =  mini;
        for(int i = n-2 ; i>= 0 ; i--){
            mini = min(mini , nums[i]);
            minel[i] = mini;
        }


        for(int i = 0 ; i < n ; i++){
            if((maxel[i]-minel[i]) <= k) return i;
        }



        return -1;

    }
};