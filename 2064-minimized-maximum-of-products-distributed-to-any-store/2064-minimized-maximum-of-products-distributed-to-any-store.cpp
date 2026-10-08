class Solution {
public:
    bool ispossible(vector<int> temp , int n, int mid){
        int part = 0;

        for(int i = 0 ; i < temp.size(); i++){
            while(temp[i] > mid){
                temp[i] -= mid;
                part++;
            }

            part++;
            temp[i] = 0;
        }

        return part <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {

        int high = INT_MIN;

        vector<int>temp;
        int ans = 0;

    

        for (int val : quantities) {
            temp.push_back(val);
            high = max(high, val);
        }

        int st = 1 , end = high;

        while(st <= end){
            int mid = st+(end-st)/2;

            if(ispossible(temp , n , mid)){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
        }

        return ans;
    }
};