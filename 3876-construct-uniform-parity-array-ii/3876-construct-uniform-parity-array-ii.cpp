class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mmOdd = INT_MAX;

        for(int x : nums1){
            if(x%2 == 1)
            mmOdd = min(mmOdd , x);
        }

        if(mmOdd == INT_MAX) return true;

        for(int x : nums1){
            if(x%2 == 0 && x < mmOdd) return false;
        }
        return true;
    }
};