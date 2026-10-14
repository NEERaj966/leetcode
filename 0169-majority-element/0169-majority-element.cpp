class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin() , nums.end());
        //     int mid = nums.size()/2;
        // return nums[mid];
        int count = 0;
        int ele = nums[0];

        for(int i = 0 ; i < nums.size(); i++){

            if(nums[i] == ele) count++;
            else count--;

            if(count < 0){
                ele = nums[i];
                count = 1;
            }
        }

        return ele;

    }
};