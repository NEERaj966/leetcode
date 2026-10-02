class Solution {
public:
    bool ispossible(vector<int> weights , int n , int days , int mid ){
        int day = 1, val = 0;

        for(int i = 0 ; i < n;i++){
            if(val+weights[i] <= mid){
                val += weights[i];
            }else{
                val = weights[i];
                day++;
            }
        }

        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = 0;
        int maxval = INT_MIN;
        int ans = 0;

        for(int val : weights){
            sum += val;

            maxval = max(maxval , val);
        }

        int st = maxval , end = sum;

        while(st <= end){
            int mid = st+(end - st)/2;

            if(ispossible(weights , n , days , mid)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
};